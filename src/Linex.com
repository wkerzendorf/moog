
c******************************************************************************
c     this common block has variables related to the lines.  Most
c     input quantities typically have single dimensions, while the 
c     things that are computed for each line at each atmosphere level
c     have double dimensions.  The variables "a", "dopp", and 
c     "kapnu0" are often over-written with plotting data,
c     so leave them alone or suffer unspeakable programming tortures.
c******************************************************************************

      real*8       a(250000,100), dopp(250000,100), kapnu0(250000,100)
      real*8       gf(250000), wave1(250000), atom1(250000), e(250000,2),
     .             chi(250000,3), amass(250000), charge(250000), d0(250000),
     .             dampnum(250000), gf1(250000), width(250000), 
     .             abundout(250000), widout(250000), strength(250000), 
     .             rdmass(250000), gambark(250000), alpbark(250000),
     .             wid1comp(250000)
      real*8       kapnu(100), taunu(100), cd(100), sline(100)
      real*8       d(5000), dellam(400), w(100),
     .             rwtab(3000), gftab(3000), gfhold
      real*8       delta, start, sstop, step,
     .             oldstart, oldstop, oldstep, olddelta
      real*8       rwlow, rwhigh, rwstep, wavestep, cogatom,
     .             delwave, wave, waveold, st1
      real*8       gammatot, gammav, gammas, gammar
      integer      lim1, lim2, mode, ndepths, ncurve, nlines,nstrong,
     .             lim1line, lim2line, ntabtot, group(250000),
     .             iabatom, molflag, dostrong, gfstyle
      character*7  damptype(250000)

      common/linex/a, dopp, kapnu0,   
     .             gf, wave1, atom1, e,
     .             chi, amass, charge, d0,
     .             dampnum, gf1, width, 
     .             abundout, widout, strength,
     .             rdmass, gambark, alpbark,
     .             wid1comp,
     .             kapnu, taunu, cd, sline,
     .             d, dellam, w,
     .             rwtab, gftab, gfhold,
     .             delta, start, sstop, step,   
     .             oldstart, oldstop, oldstep, olddelta,
     .             rwlow, rwhigh, rwstep, wavestep, cogatom,
     .             delwave, wave, waveold, st1,
     .             gammatot, gammav, gammas, gammar,
     .             lim1, lim2, mode, ndepths, ncurve, nlines,nstrong, 
     .             lim1line, lim2line, ntabtot, group,
     .             iabatom, molflag, dostrong, gfstyle
      common/lindamp/damptype

