/*********************************************************************/
/*
 * We have to declare the variables and functions from devices.a. Most
 * are not used. Used in rasterise.c and compile_g.c
 */
char cchar='#';
void default_ctype(s) char *s; {;}
void hand_C(i) int i; { ; }
void msg(s) Const char *s; { fprintf(stderr,s); }
void msg_1s(s,s1) Const char *s,*s1; { fprintf(stderr,s,s1); }
void msg_2s(s,s1,s2) Const char *s,*s1,*s2; { fprintf(stderr,s,s1,s2); }
void msg_1d(s,d) Const char *s; int d; { fprintf(stderr,s,d); }
char *defaults_file = ".sm";
float xscreen_to_pix,yscreen_to_pix;
int devnum,sm_interrupt = 0,sm_verbose = 0,
  ndev = 0,termout = 0,pdef,aspect,ldef;
float cheight,cwidth,	  /* canonical height and width of characters*/
  	     fx1,fx2,fy1,fy2,     /* User coords of graphics area    */
	     fsx,fsy,ffx,ffy;     /* Scale and offset to conversion  */
int   s_depth,s_height,	  /* pixel depth, height, */
	     s_width;		  /* 			  and width of str */
int   gx1,gx2,gy1,gy2;     /* Device coords of graphics area  */
long xp,yp;		  /* current plot position (can be offscreen)*/
float llweight;            /* Line weight		     */
int   lltype;              /* Line type: dotted, etc.         */
float 	     eexpand;             /* Global expansion of chars, pts  */
float aangle,sm_sin,sm_cos;  /* Rotation of chars and points  */
REAL *angle_vec;	  /* vector of angles, used in point */
int   n_angle_vec;	  /* dimension of angle_vec          */
REAL *expand_vec;	  /* vector of expansions, used in point */
int   n_expand_vec;	  /* dimension of expand_vec         */


/************************************************************************/
