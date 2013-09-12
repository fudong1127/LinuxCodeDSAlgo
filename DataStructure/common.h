#ifndef __COMMON_H__
#define __COMMON_H__
  #define DELETE(p)         if(p){delete p;p = NULL;} 
  #define ARRAY_SIZE(p)     (sizeof(p)/sizeof(p[0]))
#endif
