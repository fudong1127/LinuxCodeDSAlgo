#ifndef __COMMON_H__
#define __COMMON_H__

#if !defined(SUCCESS) && !defined(FAILED)
  #define SUCCESS 0
  #define FAILED  1
#endif

#if !defined(SIZE) && !defined(MIN) && !defined(MAX)
  #define     SIZE(arr)             (sizeof(arr)/sizeof(arr[0]))
  #define     MIN(a,b)              (((a)<(b))?(a):(b))
  #define     MAX(a,b)              (((a)>(b))?(a):(b))
#endif

#if !defined(BREAKIF) && !defined(BREAKIFNULL)
  #define BREAKIF(nRetVal) if (SUCCESS != nRetVal) {break;}
  #define BREAKIFNULL(p,nRetVal) if( NULL == (p)){nRetVal = FAILED;break;}
#endif

  typedef unsigned int uint;

#endif
