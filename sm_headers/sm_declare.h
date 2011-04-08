#include "copyright.h"
#if !defined(INC_OPTIONS_H)
#  include "options.h"
#endif
/*
 * Note that this file is explicitly excluded from all Makefiles
 */
/*
 * If ANSI_PROTO is defined to the preprocessor, provide prototypes for all
 * functions, other wise simply declare their return values.
 */
#ifdef ANSI_PROTO
#  define P_ARGS(A) A
#else
#  define P_ARGS(A) ()
#endif

/*
 * First various system routines, mostly to pacify lint (or gcc -Wall)
 */
/*
 * alphas define ABS in <sys/timers.h>. I don't know if POSIX allows/demands
 * this, but for now work around it.
 */
#if defined(alpha)
#  define ABS__ ABS
#  undef ABS
#endif

#if defined(ANSI_INCLUDE)
#  include <stddef.h>
#  include <stdlib.h>
#  include <string.h>
#  include <time.h>
   typedef time_t TIME_T;
#else
   typedef long TIME_T;
   int _flsbuf P_ARGS(( unsigned char, FILE * ));
   int _filbuf P_ARGS(( FILE * ));
   void abort P_ARGS(( void ));
   int abs P_ARGS(( int ));
   int atoi P_ARGS(( char * ));
   double atof P_ARGS(( Const char * ));
   char *ctime P_ARGS(( Const TIME_T * ));
   void exit P_ARGS(( int ));
   int fclose P_ARGS(( FILE * ));
   int fflush P_ARGS(( FILE * ));
   char *fgets P_ARGS(( char *, int, FILE * ));
   int fprintf P_ARGS(( FILE *, Const char *, ... ));
   int fputs P_ARGS(( Const char *, FILE * ));
   int fread P_ARGS(( Void *, long, long, FILE * ));
   void free P_ARGS(( void * ));
   int fscanf P_ARGS(( FILE *, Const char *, ... ));
   int fseek P_ARGS(( FILE *, long, int ));
   int fwrite P_ARGS(( Void *, long, long, FILE * ));
   char *getenv P_ARGS(( char * ));
   Void *malloc P_ARGS(( int ));
#if !defined(__GNUC__)
   Void *memcpy P_ARGS(( Void *, Const Void *, int ));
#endif
   void perror P_ARGS(( Const char * ));
   int printf P_ARGS(( Const char *, ... ));
   int puts P_ARGS(( Const char * ));
   void qsort P_ARGS(( Void *, int, int, int (*)()));
   int rand P_ARGS(( void ));
   Void *realloc P_ARGS(( Void *, int ));
   int scanf P_ARGS(( Const char *, ... ));
   void setbuf P_ARGS(( FILE *, char * ));
#if defined(SUN_BROKEN_DEFNS)
      char *sprintf();
#else
#  if defined(__STDC__) || defined(VMS) || defined(SYS_V)
      int sprintf P_ARGS(( char *, Const char *, ... ));
#  else
      char *sprintf P_ARGS(( char *, Const char *, ... ));
#  endif
#endif
   void srand P_ARGS(( unsigned int ));
   int sscanf P_ARGS(( Const char *, Const char *, ... ));
   char *strcat P_ARGS(( char *, Const char * ));
   char *strncat P_ARGS(( char *, Const char *, int ));
   char *strcpy P_ARGS(( char *, Const char * ));
   char *strncpy P_ARGS(( char *, Const char *, int ));
   int strcmp P_ARGS(( Const char *, Const char * ));
   int strncmp P_ARGS(( Const char *, Const char *, int ));
   char *strchr P_ARGS(( Const char *, int ));
   char *strrchr P_ARGS(( Const char *, int ));
   int strlen P_ARGS(( Const char * ));
   int system P_ARGS(( char * ));
   long time P_ARGS(( TIME_T * ));
#  if !defined(tolower)
      int tolower P_ARGS(( int ));
#  endif
#  if !defined(toupper)
      int toupper P_ARGS(( int ));
#  endif
   int ungetc P_ARGS(( int, FILE * ));
#endif
/*
 * These are not in ANSI C (but will mostly be POSIX)
 */
#if defined(NO_ALLOCA) && defined(SMBISON)
   Void *alloca P_ARGS(( int ));	/* not POSIX */
#endif
#if defined(_HPUX_SOURCE) || defined(BROKEN_GLIBC_ECVT)
   char *ecvt();
#else
   char *ecvt P_ARGS(( double, int, int *, int * ));
#endif
#if defined(sun) && defined(DEBUG)
   void malloc_debug P_ARGS(( int ));
#endif
#if !defined(HAVE_IOCTL_DEFN)
   int ioctl P_ARGS(( int, int, char * ));
#endif
char *mktemp P_ARGS(( char * ));
#if defined(POSIX_INCLUDE)
#  include <unistd.h>
#  include <fcntl.h>
#  if defined(sgi4)                   /* I don't know why this is needed */
   int kill P_ARGS(( int, int ));
#  endif
#else
   int chdir P_ARGS(( Const char * ));
   int close P_ARGS(( int ));
#if defined(__GNUC__)
#  if defined(X11_C) && defined(sun)	/* X11 code includes sys/fcntlcom.h */
      int creat();
#  else
      int creat P_ARGS(( const char *, unsigned short ));
#  endif
#else
#  if !defined(_HPUX_SOURCE)
      int creat P_ARGS(( const char *, int ));
#  endif
#endif
   int ftruncate P_ARGS(( int, long ));
   int fork P_ARGS(( void ));
#if !(defined(X11_C) && defined(sun))	/* X11 code includes unistd.h */
   int getuid P_ARGS(( void ));
#endif
   int getpid P_ARGS(( void ));
   int isatty P_ARGS(( int ));
   long lseek P_ARGS(( int, long, int ));
#if defined(SUN_BROKEN_DEFNS)
   int open P_ARGS(( ));
#else
#  if !defined(_HPUX_SOURCE)
      int open P_ARGS(( char *, int, ... ));
#  endif
#endif
   int read P_ARGS(( int, char *, int ));
   int unlink P_ARGS(( Const char * ));
   int write P_ARGS(( int, char *, int ));
#endif
/*
 * Now for struct timeval, FD_SET, and select(), which aren't in 1003.1
 */
#if defined(TIMEVAL_H)
#  include TIMEVAL_H
#endif

#if defined(FD_SET_H)
#ifdef rs6000
#include <sys/types.h>
#endif
#  include FD_SET_H
#else
   typedef int fd_set;                        /* used by select */

#  if (!defined FD_SET)
#    define FD_SET(FD,MASK) (*MASK |= (1 << FD))
#  endif
#  if (!defined FD_ISSET)
#    define FD_ISSET(FD,MASK) (*MASK & (1 << FD))
#  endif
#  if (!defined FD_ZERO)
#    define FD_ZERO(p)    bzero((char *)(p), sizeof(*(p)))
#  endif
#endif

#if defined(SELECT_H)
#  include SELECT_H
#else
   int select();			/* really int,int,int,struct timeval */
#endif
/*
 * Doubtful cases (not in ANSI)
 */
#if defined(hp) || defined(rs6000) || (0 && defined(solaris))
   int bzero P_ARGS(( char *, int ));
#endif
double hypot P_ARGS(( double, double ));
/*
 * end of alpha ABS workaround
 */
#if defined(alpha)
#  undef ABS
#  define ABS ABS__
#endif

/*
 * And now SM functions
 */
void add_marg P_ARGS(( unsigned int, char * ));
int sm_array_to_vector P_ARGS(( REAL *, int, char * ));
REAL atn2 P_ARGS(( double, double ));
REAL atof2 P_ARGS(( char * ));
LONG atoi2 P_ARGS(( char *, int, char ** ));
int sm_axis P_ARGS(( double, double, double, double, int, int, int, int, int));
void sm_box P_ARGS(( int, int, int, int ));
int buff_is_empty P_ARGS(( void ));
void chopper P_ARGS(( int, int, int, int ));
int sm_conn P_ARGS(( REAL [], REAL [], int ));
int sm_connect P_ARGS(( REAL [], REAL [], int ));
int sm_connect_if P_ARGS(( REAL [], REAL [], REAL [], int ));
int sm_contour P_ARGS(( void ));
int create_image P_ARGS(( int, int, double, double, double, double ));
int cross P_ARGS(( long, long, long, long, long, long, long, long,
		   			     long *, long *, long *, long * ));
void sm_ctype P_ARGS(( char * ));
int current_ctype P_ARGS(( void ));
#ifdef INC_IMAGE_H
   IMAGE *current_image P_ARGS(( void ));
#endif
char *current_macro P_ARGS(( void ));
void sm_curs P_ARGS(( REAL *, REAL *, int *)); /* callable SM */
int sm_cursor P_ARGS(( int ));
void declare_devs P_ARGS(( void ));
void declare_vars P_ARGS(( void ));
void default_ctype P_ARGS(( char * ));
int sm_defimage P_ARGS(( float **, double, double, double, double, int, int ));
int define P_ARGS(( char *, char *, int, int, int ));
int define_s P_ARGS(( char *, char *, char * ));
int define_history_macro P_ARGS(( char [], int, int ));
int define_key P_ARGS(( char *, int ));
void define_map P_ARGS(( char *, char * ));
void def_sy_macro P_ARGS(( char *, char * ));
void delete_history P_ARGS(( int, int, int ));
void delete_last_history P_ARGS(( int ));
void delvar_local P_ARGS(( char * ));
void sm_delimage P_ARGS(( void ));
void sm_deltable P_ARGS(( void ));
void sm_disable P_ARGS(( void ));
void sm_dot P_ARGS(( void ));
void sm_draw P_ARGS(( double, double ));
void draw_dline P_ARGS(( long, long, long, long ));
void sm_draw_point P_ARGS(( double, double, int, int ));
void draw_string P_ARGS(( char * ));
void sm_draw_surface P_ARGS(( int, double, double, REAL *, int, REAL *, int ));
void dump_stack P_ARGS(( void ));
char *edit_hist P_ARGS(( void ));
int edit_line P_ARGS(( char *, char ** ));
int sm_dither P_ARGS(( char *, char *, double, double, int ));
void sm_enable P_ARGS(( void ));
void end_while P_ARGS(( void ));
void erase_str P_ARGS(( char *, int ));
int sm_errorbar P_ARGS(( REAL [], REAL [], REAL [], int, int ));
int execute P_ARGS(( char * ));
int exists_var P_ARGS (( char *name ));
void fan_compress P_ARGS(( REAL [], REAL [], int, double, int [], int * ));
int fft P_ARGS(( REAL *, REAL *, REAL *, REAL *, int, int ));
void fcopyo P_ARGS(( int, int ));
#if defined(HSIZE)
   EDIT *find_str P_ARGS(( char *, int, int, EDIT *, EDIT * ));
#endif
void flush_dstack P_ARGS(( void ));
void flush_fstack P_ARGS(( void ));
void flush_mstack P_ARGS(( void ));
void sm_format P_ARGS(( char *, char * ));
void free_hidden P_ARGS(( void ));
void free_vector P_ARGS(( char * ));
void free_vector_local P_ARGS(( char * ));
double sm_gamma P_ARGS(( double, double ));
void gdraw P_ARGS(( double, double ));
int get1char P_ARGS(( int ));
int get_color P_ARGS(( int, int *, int *, int * ));
char *get_edit_str P_ARGS(( char * ));
char *get_full_name P_ARGS(( char [] ));
char *get_key_macro P_ARGS(( int ));
char *get_home P_ARGS (( char * ));
char *get_line P_ARGS(( int * ));
char *get_macro P_ARGS(( char *, int *, int *, int * ));
char *get_name P_ARGS(( void ));
Void *get_lnode_scope_rest P_ARGS(( void ));
char *get_val P_ARGS(( char [] ));
float sm_get_variable P_ARGS(( char * ));
char *get_variable P_ARGS(( int ));
void sm_gflush P_ARGS (( void ));
void sm_grelocate P_ARGS(( double, double ));
void sm_grid P_ARGS(( int, int ));
int gstrcpy  P_ARGS(( char [], char [], int ));
void hand_C P_ARGS(( int ));
void hand_acc P_ARGS(( int ));
#if defined(sun) && !defined(solaris) && defined(SIGKILL)	/* I've included <signal.h> */
   void hand_flt P_ARGS(( int, int, struct sigcontext * ));
#else
   void hand_flt P_ARGS(( int, int ));
#endif
void hand_ill P_ARGS(( int, int ));
void hand_io P_ARGS(( int ));
void hand_q P_ARGS(( int ));
void hand_winch P_ARGS(( int ));
int help P_ARGS(( char [] ));
void help_apropos P_ARGS(( char * ));
int help_vector P_ARGS(( char * ));
int sm_histogram P_ARGS(( REAL [], REAL [], int ));
int sm_histogram_if P_ARGS(( REAL [], REAL [], REAL [], int ));
void history_list P_ARGS(( int ));
#ifdef IMAGEN
void im_close P_ARGS(( void ));
void im_draw P_ARGS(( int, int ));
int im_fill_pt P_ARGS(( int ));
void im_line P_ARGS(( int, int, int, int ));
int im_lweight P_ARGS(( double ));
void im_page P_ARGS(( void ));
int im_setup P_ARGS(( char * ));
#endif
float image_val P_ARGS(( double, double ));
int index_variable P_ARGS(( char * ));
void init_colors P_ARGS (( void ));
int init_hist P_ARGS(( void ));
void init_vectors P_ARGS(( void ));
void init_stack P_ARGS(( void ));
int input P_ARGS(( void ));
void sm_ctype_i P_ARGS(( int ));
int is_vector P_ARGS(( char * ));
void key_macro P_ARGS(( void ));
void kill_keywords P_ARGS(( void ));
void kill_sy_macros P_ARGS(( void ));
void sm_label P_ARGS(( char * ));
void sm_levels P_ARGS(( REAL [], int ));
#if defined(YYSTYPE)
   int lexan P_ARGS(( YYSTYPE * ));
#endif
void lexflush P_ARGS(( void ));
int sm_limits P_ARGS(( double, double, double, double ));
void sm_line P_ARGS(( double, double, double, double ));
void list_edit P_ARGS(( void ));
void list_table_cols P_ARGS(( char * ));
void list_image_vars P_ARGS(( void ));
void list_internal_vars P_ARGS(( void ));
void list_vectors P_ARGS(( void ));
int load_font P_ARGS(( char * ));
int sm_location P_ARGS(( int, int, int, int ));
void sm_ltype P_ARGS(( int ));
void sm_set_ltype_expand P_ARGS(( double ));
void sm_lweight P_ARGS(( double ));
void mac_return P_ARGS(( void ));
void macro_apropos P_ARGS(( char * ));
int macro_edit P_ARGS(( char * ));
void macrolist P_ARGS(( int, int ));
char *macro_name P_ARGS(( char * ));
int main P_ARGS(( ));			/* either (void) or (int, char *[]) */
void make_local_variable P_ARGS(( char * ));
char *make_temp P_ARGS(( char * ));
char *match_pattern P_ARGS(( char *, char *, char ** ));
int map_key P_ARGS(( void ));
char *mgets P_ARGS(( char *, int ));
void sm_minmax P_ARGS(( float *, float * ));
int more P_ARGS(( char * ));
int mscanstr P_ARGS(( char *, int ));
int mscanline P_ARGS(( char *, int ));
void msg P_ARGS(( Const char * ));
void msg_1d P_ARGS(( Const char *, int ));
void msg_1f P_ARGS(( Const char *, double ));
void msg_1s P_ARGS(( Const char *, Const char * ));
void msg_2s P_ARGS(( Const char *, Const char *, Const char * ));
int next_do P_ARGS(( void ));
int next_foreach P_ARGS(( void ));
char *next_word P_ARGS(( char * ));
int not_provided P_ARGS(( void ));
void sm_notation P_ARGS(( double, double, double, double ));
void num_to_ascii P_ARGS(( double, int, char * ));
int num_or_word P_ARGS(( char [] ));
void overload P_ARGS(( char *, int ));
void allow_overload P_ARGS(( void ));
void disable_overload P_ARGS(( void ));
int parse_color P_ARGS(( char *, int *, int *, int * ));
int parse_qualifier P_ARGS(( char * ));
int sm_peek P_ARGS(( void ));
void sm_plotsym P_ARGS(( REAL [], REAL [], int, int [], int ));
void sm_points P_ARGS(( REAL [], REAL [], int ));
void sm_points_if P_ARGS(( REAL [], REAL [], REAL [], int ));
void pop_dstack P_ARGS(( void ));
void pop_fstack P_ARGS(( void ));
void pop_mstack P_ARGS(( void ));
double pow P_ARGS(( double, double ));
char *print_arg P_ARGS(( int, int ));
char *print_var P_ARGS(( char * ));
void prompt_user P_ARGS(( char [] ));
void sm_ptype P_ARGS(( REAL *, int ));
void ptype_str P_ARGS(( char *, char *, int ));
void push P_ARGS(( char *, int ));
void push_dstack P_ARGS(( char *, double, double, double ));
void push_mstack P_ARGS(( char *, int, int, int ));
int put_val P_ARGS(( char [], char [] ));
void sm_putlabel P_ARGS(( int, char * ));
void ras_close P_ARGS(( void ));
void ras_ctype P_ARGS(( int, int, int ));
void ras_draw P_ARGS(( int, int ));
void ras_erase P_ARGS(( void ));
void ras_line P_ARGS(( int, int, int, int ));
void ras_reloc P_ARGS(( int, int ));
int ras_setup P_ARGS(( char * ));
#ifdef INC_SM_H
   int ras_set_ctype P_ARGS(( COLOR *, int ));
#endif
void sm_srand P_ARGS(( long seed ));
float sm_rand P_ARGS(( void ));
void read_hist P_ARGS(( FILE * ));
int read_history_macro P_ARGS(( char * ));
int read_image P_ARGS(( char *, int, double, double, double, double, int,int,int,int ));
char *read_image_variable P_ARGS(( char * ));
void read_macros P_ARGS(( FILE * ));
int read_map P_ARGS(( char [] ));
void read_old P_ARGS(( char [], char [] ));
#ifdef INC_VECTORS_H			/* vectors.h has been included */
int read_table P_ARGS((char *, int, VECTOR **, int, int, int, int, char *, char *));
#endif
void read_table_header P_ARGS((char *, int ));
char *read_variable P_ARGS(( char [], int, int ));
int readc P_ARGS(( void ));
void sm_relocate P_ARGS(( double, double ));
void replace_last_command P_ARGS(( char * ));
void reset_chopper P_ARGS(( void ));
void reset_label_pos P_ARGS(( void ));
void reset_term P_ARGS(( void ));
void restore P_ARGS(( char * ));
void save P_ARGS(( char *, int ));
void save_ctype P_ARGS(( int ));
void save_float P_ARGS(( double ));
void save_int P_ARGS(( int ));
void save_str P_ARGS(( char * ));
void save_variables P_ARGS(( FILE * ));
void save_vectors P_ARGS(( FILE * ));
void sc_draw P_ARGS(( long, long ));
void sc_relocate P_ARGS(( long, long ));
void set_all_internal P_ARGS(( void ));
void set_angle P_ARGS(( REAL *, int ));
void set_aspect P_ARGS(( double ));
#ifdef INC_VECTORS_H			/* vectors.h has been included */
void set_color P_ARGS(( VECTOR * ));
#endif
int sm_add_ctype P_ARGS(( const char *, int, int, int ));
int sm_delete_ctype P_ARGS(( const char * ));
void sm_set_ctypes P_ARGS(( REAL *, int ));
void set_cursor_vectors P_ARGS(( char *, char *, char * ));
void set_data_file P_ARGS(( char * ));
void set_defaults_file P_ARGS(( char *, char * ));
void set_dev P_ARGS(( void ));
int set_device P_ARGS(( char * ));
void set_exit_status P_ARGS(( int ));
void set_expand P_ARGS(( REAL *, int ));
void set_eexpand P_ARGS(( double ));
void set_help_vector P_ARGS(( char *, char * ));
void set_help_path P_ARGS(( void ));
void set_high P_ARGS(( short *, short *, int ));
void set_image_name P_ARGS(( char * ));
void set_image_variable P_ARGS(( char *, char * ));
void set_pf_key P_ARGS(( char *, int ));
void set_scale P_ARGS(( void ));
int set_term_type P_ARGS(( char *, int ));
void set_term P_ARGS(( void ));
void set_viewpoint_params P_ARGS(( double, double, double ));
void setvar P_ARGS(( char *, char [] ));
void setvar_internal P_ARGS(( char * ));
void setvar_local P_ARGS(( char * ));
int IC_strncmp P_ARGS(( Const char *, Const char *, int ));
void sm_set_viewpoint P_ARGS(( double, double, double ));
#if defined(INC_STDGRAPH_H)
int sge_execute P_ARGS(( char *, char *, REGISTER * ));
#endif
void close_metafile P_ARGS(( void ));
int open_metafile P_ARGS(( char * ));
int playback_metafile P_ARGS(( char * ));
int meta_char P_ARGS(( char *, int, int ));
void meta_close P_ARGS(( void ));
void meta_ctype P_ARGS(( int, int, int ));
int meta_cursor P_ARGS(( int, int *, int * ));
void meta_draw P_ARGS(( int, int ));
int  meta_dot P_ARGS(( int, int ));
void meta_erase P_ARGS(( void ));
int meta_fill_pt P_ARGS(( int ));
void meta_gflush P_ARGS(( void ));
void meta_idle P_ARGS(( void ));
void meta_line P_ARGS(( int, int, int, int ));
int meta_ltype P_ARGS(( int ));
int meta_lweight P_ARGS(( double ));
#ifdef INC_SM_H
   int meta_set_ctype P_ARGS(( COLOR *, int ));
#endif
void meta_reloc P_ARGS(( int, int ));
int  meta_setup P_ARGS(( char * ));
void meta_enable P_ARGS(( void ));
void meta_page P_ARGS(( void ));
void meta_redraw P_ARGS(( int ));
#ifdef SGI
int sgi_char P_ARGS(( char *, int, int ));
int sgi_curs P_ARGS(( int *, int * ));
void sgi_close P_ARGS(( void ));
void sgi_ctype P_ARGS(( int, int, int ));
int sgi_cursor P_ARGS(( int, int *, int * ));
void sgi_draw P_ARGS(( int, int ));
void sgi_erase P_ARGS(( void ));
int sgi_fill_pt P_ARGS(( int ));
void sgi_gflush P_ARGS(( void ));
void sgi_idle P_ARGS(( void ));
void sgi_line P_ARGS(( int, int, int, int ));
int sgi_ltype P_ARGS(( int ));
int sgi_lweight P_ARGS(( double ));
void sgi_redraw P_ARGS(( int ));
void sgi_reloc P_ARGS(( int, int ));
#ifdef INC_SM_H
int sgi_set_ctype P_ARGS(( COLOR *, int ));
#endif
int sgi_setup P_ARGS(( char * ));
#endif
void sm_shade P_ARGS(( double, REAL *, REAL *, int ));
int shade_hist P_ARGS(( double, REAL *, REAL *, int ));
int sm_main P_ARGS(( int, char ** ));
int sm_parser P_ARGS(( char * ));
void sort_flt P_ARGS(( REAL [], int ));
void sort_flt_inds P_ARGS(( REAL [], int [], int ));
void sort_long_inds P_ARGS(( LONG [], int [], int ));
void sort_str_inds P_ARGS(( char *[], int [], int ));
int spline P_ARGS(( char *, char *, char *, char * ));
void start_line P_ARGS(( void ));
int stg_char P_ARGS(( char [], int, int ));
void stg_char_size P_ARGS(( int, int ));
void stg_close P_ARGS(( void ));
void stg_ctrl  P_ARGS(( char [] ));
void stg_ctrl1  P_ARGS(( char [], int ));
void stg_fctrl1  P_ARGS(( char [], double ));
void stg_ctrl2  P_ARGS(( char [], int, int ));
void stg_ctrl3  P_ARGS(( char [], int, int, int ));
void stg_ctype P_ARGS(( int, int, int ));
int stg_cursor P_ARGS(( int, int *, int * ));
int stg_dot P_ARGS(( int, int ));
void stg_draw P_ARGS(( int, int ));
#if defined(INC_STDGRAPH_H)
int stg_encode P_ARGS(( char *, char *, REGISTER *));
#endif
void stg_enable P_ARGS(( void ));
void stg_erase P_ARGS(( void ));
int stg_fill_pt P_ARGS(( int ));
int stg_fill_polygon P_ARGS(( int style, short *x, short *y, int n));
void stg_gflush P_ARGS(( void ));
void stg_idle P_ARGS(( void ));
void stg_line P_ARGS(( int, int, int, int ));
int stg_list P_ARGS(( char * ));
int stg_ltype P_ARGS(( int ));
void stg_page P_ARGS(( void ));
int stg_lweight P_ARGS(( double ));
void stg_reloc P_ARGS(( int, int ));
#ifdef INC_SM_H
int stg_set_ctype P_ARGS(( COLOR *, int ));
#endif
int stg_setup P_ARGS(( char [] ));
int str_to_argv P_ARGS(( char *, char *[], int * ));
#if !defined(str_scanf)
   int str_scanf P_ARGS(( char *, char *, ... ));
#endif
void string_size P_ARGS(( char *, float *, float *, float * ));
#ifdef SUN_VIEW
int sunv_char P_ARGS(( char *, int, int ));
void sunv_close P_ARGS(( void ));
void sunv_ctype P_ARGS(( int, int, int ));
int sunv_cursor P_ARGS(( int, int *, int * ));
void sunv_draw P_ARGS(( int, int ));
void sunv_enable P_ARGS(( void ));
void sunv_erase P_ARGS(( void ));
int sunv_fill_pt P_ARGS(( int ));
void sunv_gflush P_ARGS(( void ));
void sunv_idle P_ARGS(( void ));
void sunv_line P_ARGS(( int, int, int, int ));
int sunv_ltype P_ARGS(( int ));
int sunv_lweight P_ARGS(( double ));
void sunv_page P_ARGS(( void ));
void sunv_reloc P_ARGS(( int, int ));
#ifdef INC_SM_H
int sunv_set_ctype P_ARGS(( COLOR *, int ));
#endif
int sunv_setup P_ARGS(( char * ));
#endif
#ifdef SUNWINDOWS
int sun_char P_ARGS(( char *, int, int ));
void sun_close P_ARGS(( void ));
void sun_ctype P_ARGS(( int, int, int ));
int sun_cursor P_ARGS(( int, int *, int * ));
void sun_draw P_ARGS(( int, int ));
void sun_enable P_ARGS(( void ));
void sun_erase P_ARGS(( void ));
int sun_fill_pt P_ARGS(( int ));
void sun_idle P_ARGS(( void ));
void sun_line P_ARGS(( int, int, int, int ));
int sun_lweight P_ARGS(( double ));
void sun_reloc P_ARGS(( int, int ));
#ifdef INC_SM_H
int sun_set_ctype P_ARGS(( COLOR *, int ));
#endif
int sun_setup P_ARGS(( char [] ));
#endif
#ifdef SVGALIB
int svgalib_char P_ARGS(( char *, int, int ));
void svgalib_close P_ARGS(( void ));
void svgalib_ctype P_ARGS(( int, int, int ));
int svgalib_cursor P_ARGS(( int, int *, int * ));
int svgalib_dot P_ARGS(( int, int ));
void svgalib_draw P_ARGS(( int, int ));
void svgalib_enable P_ARGS(( void ));
void svgalib_erase P_ARGS(( void ));
int svgalib_fill_pt P_ARGS(( int ));
int svgalib_fill_polygon P_ARGS(( int style, short *x, short *y, int n));
void svgalib_gflush P_ARGS(( void ));
void svgalib_idle P_ARGS(( void ));
void svgalib_line P_ARGS(( int, int, int, int ));
int svgalib_ltype P_ARGS(( int ));
int svgalib_lweight P_ARGS(( double ));
void svgalib_page P_ARGS(( void ));
void svgalib_redraw P_ARGS(( int ));
void svgalib_reloc P_ARGS(( int, int ));
#ifdef INC_SM_H
int svgalib_set_ctype P_ARGS(( COLOR *, int ));
#endif
int svgalib_setup P_ARGS(( char * ));
#endif
int sm_suspend P_ARGS(( void ));
void sm_ticksize P_ARGS(( double, double, double, double ));
int ttclose P_ARGS(( int ));
void ttflush P_ARGS(( int ));
int ttopen P_ARGS(( char * ));
void ttwrite P_ARGS(( int, char *, int ));
int tty_binsearch  P_ARGS(( int, int [], int ));
int undefine_key P_ARGS(( char * ));
int undefine_macros P_ARGS(( char [] ));
int undefined P_ARGS(( void ));
int unput P_ARGS(( int ));
void unreadc P_ARGS(( int ));
void unsave_str P_ARGS(( void ));
#ifdef UNIXPC
int upc_char P_ARGS(( char *, int, int ));
void upc_close P_ARGS(( void ));
void upc_ctype P_ARGS(( int, int, int ));
int upc_cursor P_ARGS(( int, int *, int * ));
int upc_dot P_ARGS(( int, int ));
void upc_draw P_ARGS(( int, int ));
void upc_enable P_ARGS(( void ));
void upc_erase P_ARGS(( void ));
int upc_fill_pt P_ARGS(( int ));
void upc_gflush P_ARGS(( void ));
void upc_idle P_ARGS(( void ));
void upc_line P_ARGS(( int, int, int, int ));
int upc_ltype P_ARGS(( int ));
int upc_lweight P_ARGS(( double ));
void upc_reloc P_ARGS(( int, int ));
#ifdef INC_SM_H
int upc_set_ctype P_ARGS(( COLOR *, int ));
#endif
int upc_setup P_ARGS(( char * ));
#endif
#if defined(__BORLANDC__) || defined (WIN32)
#  if defined(_Windows)
      int msw_char P_ARGS(( char *, int, int ));
      void msw_close P_ARGS(( void ));
      void msw_ctype P_ARGS(( int, int, int ));
      int msw_cursor P_ARGS(( int, int *, int * ));
      int msw_dot P_ARGS(( int, int ));
      void msw_draw P_ARGS(( int, int ));
      void msw_enable P_ARGS(( void ));
      void msw_erase P_ARGS(( void ));
      int msw_fill_pt P_ARGS(( int ));
      void msw_gflush P_ARGS(( void ));
      void msw_idle P_ARGS(( void ));
      void msw_line P_ARGS(( int, int, int, int ));
      int msw_ltype P_ARGS(( int ));
      int msw_lweight P_ARGS(( int ));
      void msw_reloc P_ARGS(( int, int ));
#     if defined(INC_SM_H)
	 int msw_set_ctype P_ARGS(( COLOR *, int ));
#     endif
      int msw_setup P_ARGS(( char * ));
#  else
      int bgi_char P_ARGS(( char *, int, int ));
      void bgi_close P_ARGS(( void ));
      void bgi_ctype P_ARGS(( int, int, int ));
      int bgi_cursor P_ARGS(( int, int *, int * ));
      int bgi_dot P_ARGS(( int, int ));
      void bgi_draw P_ARGS(( int, int ));
      void bgi_enable P_ARGS(( void ));
      void bgi_erase P_ARGS(( void ));
      int bgi_fill_pt P_ARGS(( int ));
      void bgi_gflush P_ARGS(( void ));
      void bgi_idle P_ARGS(( void ));
      void bgi_line P_ARGS(( int, int, int, int ));
      int bgi_ltype P_ARGS(( int ));
      int bgi_lweight P_ARGS(( int ));
      void bgi_reloc P_ARGS(( int, int ));
#     if defined(INC_SM_H)
         int bgi_set_ctype P_ARGS(( COLOR *, int ));
#     endif
      int bgi_setup P_ARGS(( char * ));
#  endif
#endif
#if defined(VAXUIS)
   int uis_char P_ARGS(( char *, int, int ));
   void uis_close P_ARGS(( void ));
   void uis_ctype P_ARGS(( int, int, int ));
   int uis_cursor P_ARGS(( int, int *, int * ));
   void uis_draw P_ARGS(( int, int ));
   int  uis_dot P_ARGS(( int, int ));
   void uis_erase P_ARGS(( void ));
   int uis_fill_pt P_ARGS(( int ));
   void uis_gflush P_ARGS(( void ));
   void uis_idle P_ARGS(( void ));
   void uis_line P_ARGS(( int, int, int, int ));
   int uis_ltype P_ARGS(( int ));
   int uis_lweight P_ARGS(( double ));
   int uis_set_ctype P_ARGS(( COLOR *, int ));
   void uis_reloc P_ARGS(( int, int ));
   int  uis_setup P_ARGS(( char * ));
   void uis_enable P_ARGS(( void ));
#endif
#if defined(OS2PM)
   	int pm_char P_ARGS(( char *, int, int ));
   	void pm_close P_ARGS(( void ));
   	void pm_ctype P_ARGS(( int, int, int ));
   	int pm_cursor P_ARGS(( int, int *, int * ));
	void pm_draw P_ARGS(( int, int ));
	int  pm_dot P_ARGS(( int, int ));
	void pm_erase P_ARGS(( void ));
	int pm_fill_pt P_ARGS(( int ));
	void pm_gflush P_ARGS(( void ));
	void pm_idle P_ARGS(( void ));
	void pm_line P_ARGS(( int, int, int, int ));
	int pm_ltype P_ARGS(( int ));
	int pm_lweight P_ARGS(( double ));
#       if defined(INC_SM_H)
           int pm_set_ctype P_ARGS(( COLOR *, int ));
#       endif
	void pm_reloc P_ARGS(( int, int ));
	int  pm_setup P_ARGS(( char * ));
	void pm_enable P_ARGS(( void ));
#endif

void userfn P_ARGS(( int *, char * ));
void varlist P_ARGS(( int, int ));
void version P_ARGS(( void ));
int what_is P_ARGS(( char [] ));
char *whatis_ptype P_ARGS (( void ));
void sm_window P_ARGS(( int, int, int, int, int, int ));
int would_clobber P_ARGS(( char * ));
void write_hist P_ARGS(( void ));
void write_image P_ARGS(( Const char * ));
void write_macros P_ARGS(( FILE *, int ));
int write_one_macro P_ARGS(( char *, char *, int ));
#ifdef INC_VECTORS_H			/* vectors.h has been included */
void write_table P_ARGS(( Const char *, Const char *, int, Const VECTOR **, int ));
#endif
#ifdef X11
int x11_char P_ARGS(( char *, int, int ));
void x11_close P_ARGS(( void ));
void x11_ctype P_ARGS(( int, int, int ));
int x11_cursor P_ARGS(( int, int *, int * ));
int x11_dot P_ARGS(( int, int ));
void x11_draw P_ARGS(( int, int ));
void x11_erase P_ARGS(( void ));
int x11_fill_pt P_ARGS(( int ));
int x11_fill_polygon P_ARGS(( int style, short *x, short *y, int n));
void x11_gflush P_ARGS(( void ));
void x11_idle P_ARGS(( void ));
void x11_line P_ARGS(( int, int, int, int ));
int x11_ltype P_ARGS(( int ));
int x11_lweight P_ARGS(( double ));
void x11_page P_ARGS(( void ));
void x11_redraw P_ARGS(( int ));
void x11_reloc P_ARGS(( int, int ));
#ifdef INC_SM_H
int x11_set_ctype P_ARGS(( COLOR *, int ));
#endif
int x11_setup P_ARGS(( char * ));
#endif
#ifdef XWINDOWS
int x_char P_ARGS(( char *, int, int ));
void x_close P_ARGS(( void ));
void x_ctype P_ARGS(( int, int, int ));
int x_cursor P_ARGS(( int, int *, int * ));
void x_draw P_ARGS(( int, int ));
void x_erase P_ARGS(( void ));
int x_fill_pt P_ARGS(( int ));
void x_gflush P_ARGS(( void ));
void x_idle P_ARGS(( void ));
void x_line P_ARGS(( int, int, int, int ));
void x_redraw P_ARGS(( int ));
void x_reloc P_ARGS(( int, int ));
int x_setup P_ARGS(( char * ));
#endif
void sm_xlabel P_ARGS(( char * ));
void sm_ylabel P_ARGS(( char * ));
void yyerror P_ARGS(( char [] ));
#if defined(YYSTYPE)
#  if defined(YYBISON)          /* a bison later than 1.14 */
      int yylex P_ARGS(( YYSTYPE * ));
#  else
      int yylex P_ARGS(( YYSTYPE *, Void * ));
#  endif
#endif
int yyparse P_ARGS(( void ));

#ifdef INC_YACCUN_H
void freelist P_ARGS(( TOK_LIST * ));
TOK_LIST *getlist P_ARGS(( TOK_LIST * ));
void push_fstack P_ARGS(( char *, TOK_LIST *));
void setsym P_ARGS(( TOK_LIST *));
#endif

#ifdef INC_TTY_H
int g_ttyload  P_ARGS(( char [], char [], TTY * ));
int initialise P_ARGS(( TTY *, char [] ));
int tty_fetch_entry  P_ARGS(( FILE *, char [], TTY * ));
char *tty_find_capability P_ARGS(( TTY *, char [] ));
void tty_index_caps P_ARGS(( TTY *, int [], int [] ));
int tty_scan_termcap_file P_ARGS(( TTY *, char [], char [] ));
void ttydelay  P_ARGS(( int, TTY *, int ));
TTY *ttygdes P_ARGS(( int, char *[] ));
int ttygetb  P_ARGS(( TTY *, char [] ));
int ttygeti  P_ARGS(( TTY *, char [] ));
float ttygetr  P_ARGS(( TTY *, char [] ));
int ttygets P_ARGS(( TTY *, char [], char [], int ));
TTY *ttyopen P_ARGS(( char [], int, char *[], int (*)() ));
void ttyputs  P_ARGS(( int, TTY *, char *, int, int ));
#endif

#ifdef INC_IMAGE_H
void freeimage P_ARGS(( IMAGE ** ));
IMAGE *get_image P_ARGS(( char *, int, int, int, int, int ));
#endif

#ifdef INC_TREE_H			/* tree.h has been included */
void delete_node P_ARGS(( char *, TREE * ));
void delete_node_local P_ARGS(( char *, TREE * ));
Void *get_rest P_ARGS(( char *, TREE * ));
void insert_node P_ARGS(( char *, TREE * ));
void insert_node_local P_ARGS(( char *, TREE * ));
void kill_tree P_ARGS(( TREE * ));
void list_nodes P_ARGS(( TREE *, void (*)() ));
#endif

void make_vector_local P_ARGS(( char [] )); /* in VECTOR tree */
void make_local_vector P_ARGS(( char [] )); /* in macro stack */
#ifdef INC_VECTORS_H			/* vectors.h has been included */
int check_vec P_ARGS(( VECTOR *, VECTOR *, VECTOR * ));
void copy_vector P_ARGS(( char *, VECTOR ));
int get_vector P_ARGS(( char *, VECTOR * ));
VECTOR *get_vector_ptr P_ARGS(( char * ));
int make_anon_vector P_ARGS(( VECTOR *, int, int ));
VECTOR *make_vector P_ARGS(( char [], int, int ));
void print_vec P_ARGS(( char *, char *, char *, int, VECTOR **, int ));
int read_column P_ARGS(( int, char [], int [], VECTOR *[], int, int, int, char * ));
int read_row P_ARGS(( char [], int, VECTOR * ));
void vec_abs P_ARGS(( VECTOR *, VECTOR * ));
void vec_acos P_ARGS(( VECTOR *, VECTOR * ));
void vec_add P_ARGS(( VECTOR *, VECTOR *, VECTOR * ));
void vec_and P_ARGS(( VECTOR *, VECTOR *, VECTOR * ));
void vec_asin P_ARGS(( VECTOR *, VECTOR * ));
void vec_axis P_ARGS(( double, double, VECTOR *, VECTOR *, VECTOR *, int, int,
		      int, int, int ));
void vec_atan P_ARGS(( VECTOR *, VECTOR * ));
void vec_atan2 P_ARGS(( VECTOR *, VECTOR *, VECTOR * ));
void vec_bitand P_ARGS(( VECTOR *, VECTOR *, VECTOR * ));
void vec_bitor P_ARGS(( VECTOR *, VECTOR *, VECTOR * ));
void vec_bitshift P_ARGS(( VECTOR *, VECTOR *, VECTOR *, int ));
void vec_cast_float P_ARGS(( VECTOR *, VECTOR * ));
void vec_cast_long P_ARGS(( VECTOR *, VECTOR * ));
void vec_convert_float P_ARGS(( VECTOR * ));
void vec_convert_long P_ARGS(( VECTOR * ));
void vec_concat P_ARGS(( VECTOR *, VECTOR *, VECTOR * ));
void vec_cos P_ARGS(( VECTOR *, VECTOR * ));
void vec_ctype P_ARGS(( VECTOR * ));
void vec_divide P_ARGS(( VECTOR *, VECTOR *, VECTOR * ));
int vec_do P_ARGS(( VECTOR *, double, double, double ));
void vec_eq P_ARGS(( VECTOR *, VECTOR *, VECTOR * ));
void vec_exp P_ARGS(( VECTOR *, VECTOR * ));
void vec_float P_ARGS(( VECTOR *, VECTOR * ));
void vec_free P_ARGS(( VECTOR * ));
void vec_gamma P_ARGS(( VECTOR *, VECTOR *, VECTOR * ));
void vec_ge P_ARGS(( VECTOR *, VECTOR *, VECTOR * ));
void vec_gt P_ARGS(( VECTOR *, VECTOR *, VECTOR * ));
void vec_hist P_ARGS(( VECTOR *, VECTOR *, VECTOR * ));
void vec_get_image_from_index P_ARGS(( VECTOR *, VECTOR *, VECTOR * ));
void vec_init P_ARGS((VECTOR *vec, int type));
void vec_int P_ARGS(( VECTOR *, VECTOR * ));
void vec_interp P_ARGS(( VECTOR *, VECTOR *, VECTOR * ));
void vec_index P_ARGS(( VECTOR *, VECTOR *, VECTOR * ));
void vec_length P_ARGS(( VECTOR *, VECTOR * ));
void vec_lg P_ARGS(( VECTOR *, VECTOR * ));
void vec_ln P_ARGS(( VECTOR *, VECTOR * ));
int vec_malloc P_ARGS(( VECTOR *, int ));
void vec_mod P_ARGS(( VECTOR *, VECTOR *, VECTOR * ));
void vec_multiply P_ARGS(( VECTOR *, VECTOR *, VECTOR * ));
void vec_ne P_ARGS(( VECTOR *, VECTOR *, VECTOR * ));
void vec_or P_ARGS(( VECTOR *, VECTOR *, VECTOR * ));
void vec_power P_ARGS(( VECTOR *, VECTOR *, VECTOR * ));
void vec_random P_ARGS(( int, VECTOR * ));
void set_random P_ARGS(( long ));
int vec_realloc P_ARGS(( VECTOR *, int ));
void vec_set_image_from_index P_ARGS(( VECTOR *, VECTOR *, VECTOR * ));
void vec_sin P_ARGS(( VECTOR *, VECTOR * ));
void vec_sprintf P_ARGS(( VECTOR *, VECTOR *, VECTOR * ));
void vec_sqrt P_ARGS(( VECTOR *, VECTOR * ));
void vec_string P_ARGS(( VECTOR *, VECTOR * ));
void vec_strlen P_ARGS(( VECTOR *, VECTOR * ));
void vec_subscript P_ARGS(( VECTOR *, VECTOR *, VECTOR * ));
void vec_substr P_ARGS(( VECTOR *, VECTOR *, VECTOR *, VECTOR * ));
void vec_subtract P_ARGS(( VECTOR *, VECTOR *, VECTOR * ));
void vec_tan P_ARGS(( VECTOR *, VECTOR * ));
void vec_ternary P_ARGS(( VECTOR *, VECTOR *, VECTOR *, VECTOR * ));
int vec_value P_ARGS(( VECTOR *, double ));
int vec_ivalue P_ARGS(( VECTOR *, LONG ));
Const VECTOR *zero_vec P_ARGS(( void ));
#endif
/*
 * These are only used by interface.c
 */
void sm_alpha P_ARGS(( void ));
void sm_angle P_ARGS(( double ));
void sm_defvar P_ARGS(( char *, char * ));
int sm_device P_ARGS(( char * ));
void sm_erase P_ARGS(( void ));
void sm_expand P_ARGS(( double ));
void sm_identification P_ARGS(( char * ));
float sm_get_variable P_ARGS(( char * ));
void sm_graphics P_ARGS(( void ));
void sm_hardcopy P_ARGS(( void ));
void sm_page P_ARGS(( void ));
void sm_redraw P_ARGS(( int ));
void sm_toscreen P_ARGS(( double, double, int *, int * ));
