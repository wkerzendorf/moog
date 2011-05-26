#!/usr/bin/env python

import logging
import numpy as np
import os
import tempfile


class moog():

    '''

    A class of functions and wrappers to make using MOOG in Python
    that little bit easier.

    '''


    def __init__(self):
        pass
    
    @staticmethod
    def run(atmosphere_model, line_list, stronglines_list=None, wavelength_range=[], wavelength_step=0.1, obspectrum=None, **kwargs):
        
        '''
        
        Runs MOOG with the given input parameters and returns a numpy array of
        the outputted smooth spectrum.
       
        Inputs
        -----

        atmosphere_model    :   Location of your model atmosphere file

        line_list           :   Location of your line list

        stronglines_list    :   Location of your strong lines list. This defaults
                                to None because it is only used if the 'strong'
                                keyword parameter is also set to 1.

        wavelength_range    :   A starting and ending wavelength range for MOOG
                                to synthesise over. Units are in Angstroms by
                                default unless otherwise specified by the 'units'
                                keyword argument 

        wavelength_step     :   Wavelength stepping size. Angstroms by default
                                unless overwritten by the 'units' keyword
                                argument.

        obspectrum          :   Location of an observed spectrum file to show as
                                a comparison

        

        Additional keyword arguments
        ----------------------------

        These additional keyword arguments allow the user to have full control
        over what is put into the MOOG input file. The default values are:

        terminal        'x11'
        
        atmosphere      1

        molecules       2
        
        trudamp         1

        lines           1

        flux/int        1

        damping         0
        
        units           0

        iraf            0

        plot            2

        obspectrum      1       Unless obspectrum is provided to the function.

        opacit          0

        freeform        0

        strong          0       Unless a strong lines list is provided.

        plotpars        1       0.75 Gaussian smoothing by default. Show full
                                synthesized spectral range with y:[0, 1.2]

        histogram       0

        synlimits               Defaults to the wavelength range provided and
                                the given wavelength step size, and the delta
                                defaults to the wavelength step size.

        Outputs
        -------

        A numpy two-dimensional spectrum which contains the wavelength in the
        entire first column, and normalised smoothed flux in the second column


        '''
        
        
        # Path checks for input files
        
        if atmosphere_model != None:    
            if not os.path.exists(atmosphere_model):
                raise IOError('Atmosphere model file "%s" could not be found.' % (atmosphere_model, ))  
        else: raise InputError('An atmosphere model file is required.')
            
            
        if line_list != None:
            if not os.path.exists(line_list):
                raise IOError('Line list file "%s" could not be found.' % (line_list, ))
        else: raise InputError('A line list file is required.')
        
        if kwargs.has_key('strong') and kwargs['strong'] > 0:
            if stronglines_list != None:
                if not os.path.exists(stronglines_list):
                    raise IOError('The strong lines list "%s" could not be found.' % (stronglines_list, ))
            else: raise InputError('A strong lines list is required if the keyword argument strong is not zero.')

        if wavelength_range == []:
            raise InputError('Wavelength range to synthesise must be provided.')
        
        try:
            wavelength_step = float(wavelength_step)
        
        except TypeError:
            raise TypeError('Wavelength step provided must be a positive floating point-type.')
        
        else:
            if not wavelength_step > 0:
                raise ValueError('Wavelength step provided must be a positive float.')
        
        try:
            map(float, wavelength_range)
            
        except TypeError:
            raise TypeError('Wavelength region must be specified as a starting and ending floating point-type.')
        
        bounds = (3500., 12000.)
        if wavelength_range[0] < bounds[0] or wavelength_range[0] > bounds[1]:
            raise ValueError('Starting wavelength region is outside the limiting bounds of %4.0f to %4.0f Angstroms.' % bounds)
        
        if wavelength_range[1] < bounds[0] or wavelength_range[1] > bounds[1]:
            raise ValueError('Ending wavelength region is outside the limiting bounds of %4.0f to %4.0f Angstroms.' % bounds)
        
    

        default_kwargs = {
               'atmosphere'    :   1,  
               'molecules'     :   2,  
               'trudamp'       :   1,  # Sure, why not? It's a black art anyway!
               'lines'         :   1, 
               'terminal'      :   'x11',
               'flux/int'      :   1, 
               'damping'       :   0, 
               'units'         :   0,  
               'iraf'          :   0,
               'plot'          :   2,
               'obspectrum'    :   0,
               'opacit'        :   0,
               'freeform'      :   0, 
               'strong'        :   0, 
               'plotpars'      :   "1\n\t%4.2f\t%4.2f\t%1.2f\t%1.2f\n\t%1.2f\t%1.2f\t%1.2f\t%1.2f\n\tg\t%1.2f\t%1.2f\t%1.2f\t%1.2f\t%1.2f" % (float(wavelength_range[0]), float(wavelength_range[1]), 0.0, 1.2, 0.0, 0.0, 0.0, 1.0, 0.75, 0.0, 0.0, 0.0, 0.0, ),
               'histogram'     :   0,
               'synlimits'     :   "\n\t%4.1f\t%4.1f\t%s\t%s" % (float(wavelength_range[0]), float(wavelength_range[1]), wavelength_step, wavelength_step, ),
               
           }
   
        # Fill the keyword arguments with the defaults if they don't exist already
        
        for key, value in default_kwargs.iteritems():
            if not kwargs.has_key(key):
                kwargs[key] = value
                
        temp_dir = tempfile.gettempdir()
        temp_dir = '/tmp/'
        
        # Generate a MOOG-compatible run file
        
        moog_filename = os.path.join(temp_dir, 'batch.par')
        
        if os.path.exists(moog_filename):
            logging.warn('Temporary MOOG file already exists (%s), over-writing...' % (moog_filename, ))
            os.system('rm -f %s' % (moog_filename, ))
            
        # Generate all the temporary input/output files to handle the MOOG data
        
        _, summary_out = tempfile.mkstemp(suffix='_summary.out', prefix='moog_', dir=temp_dir, text=True)
        _, standard_out = tempfile.mkstemp(suffix='_standard.out', prefix='moog_', dir=temp_dir, text=True)
        _, smoothed_out = tempfile.mkstemp(suffix='_smoothed.out', prefix='moog_', dir=temp_dir, text=True)
        _, hardpost_out = tempfile.mkstemp(suffix='_hardpost.out', prefix='moog_', dir=temp_dir, text=True)
        
        
        # And the moog files itself
        _, moog_in = tempfile.mkstemp(suffix='.proc', prefix='moog_', dir=temp_dir, text=True)
        _, moog_out = tempfile.mkstemp(suffix='_log.out', prefix='moog_', dir=temp_dir, text=True)
        

        moog_contents = """gridsynth
terminal       '%s'
model_in       '%s'
summary_out    '%s'
standard_out   '%s'
smoothed_out   '%s'
hardpost_out   '%s'
lines_in       '%s'
""" % (kwargs['terminal'], atmosphere_model, summary_out, standard_out, smoothed_out, hardpost_out, line_list, )


        if obspectrum > 0:
            moog_contents += "observed_in    '%s'\n" % (obspectrum, )
        
        if kwargs['strong'] > 0:
            moog_contents += "stronglines_in '%s'\n" % (stronglines_list, )
            

        settings = ['atmosphere', 'molecules', 'trudamp', 'lines', 'strong', 'flux/int', 'damping', 'units', 'iraf', 'plot', 'opacit', 'freeform', 'obspectrum', 'histogram', 'synlimits']
        if kwargs['plotpars'] != 0:
            settings.append('plotpars')
        
        for setting in settings:
            moog_contents += "%s %s\n" % (setting + ' ' * (14 - len(setting)), kwargs[setting], )
        
            
        # Finally
        moog_contents += "RUN 1\n"
        
        moog = open(moog_in, 'w')
        moog.writelines(moog_contents)
        moog.close()

        # Let's try nothing
        os.system('moog %s > %s' % (moog_in, moog_out, ))
        
        output_file = open(moog_out, 'r')
        output = output_file.readlines()
        output_file.close()

        for line in output:
            if 'ERROR' in line:
                raise MOOGError("MOOG returned the following error:\n\n\t%s\n\n Input/Output files:\n%s" % (line, "\n\t".join([moog_in, atmosphere_model, stronglines_list, summary_out, standard_out, smoothed_out, hardpost_out]), ))
        
        
        # Check that we actually got a spectrum
        smoothed_file = open(smoothed_out, 'r')
        if len(smoothed_file.readlines()) == 0:
            raise MOOGError('Could not find spectrum synthesised by MOOG')
        
        # Load up the spectrum data
        spectrum_data = np.loadtxt(smoothed_out, skiprows=2)
        
        removeable_files = [moog_in, moog_out, summary_out, standard_out, smoothed_out, hardpost_out]
        for removeable_file in removeable_files:
            if os.path.exists(removeable_file):
                os.remove(removeable_file)
        
        
        return spectrum_data


class MOOGError(Exception):
    
    def __init__(self, value):
        self.parameter = value
        
    def __str__(self):
        return repr(self.parameter)

