
      subroutine defcolor (icolor)
c******************************************************************************
c     This routine decides on whether to call for a black & white hardcopy
c     plot or a colorful screen plot
c******************************************************************************

      include 'Pstuff.com'
      character*8 colors(8)
      character*1 cnull
      cnull = char(0)

c*****assign colors to character arrays
      colors(1) = 'white' // cnull
      colors(2) = 'red' // cnull
      colors(3) = 'cyan' // cnull
      colors(4) = 'yellow' // cnull
      colors(5) = 'green' // cnull
      colors(6) = 'magenta' // cnull
      colors(7) = 'blue' // cnull
      colors(8) = 'black' // cnull


      if (choice.eq.'h' .or. choice.eq.'f' .or.
     .    choice.eq.'g') then
         call sm_ctype (colors(8))
      else
         call sm_ctype (colors(icolor))
      endif

      
      return
      end




