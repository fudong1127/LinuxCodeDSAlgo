#ifndef __OPENCLOSEPRINCIPLE_H__
#define __OPENCLOSEPRINCIPLE_H__

  class Shape{
      public:
        virtual void showDetails();
  };
  
  class Circle : public Shape{
      private:
        int radius;

      public:
        Circle(int rad){
            this->radius = rad;
        }
        virtual void showDetails();
  };
  
  class Rectangle : public Shape{
      private:
        int length;
        int breadth;

      public:
        Rectangle(int len,int bdth){
            this->length  = len;
            this->breadth = bdth;
        }
        virtual void showDetails();
  };
  
  class Triangle : public Shape{
      private:
        int height;
        int base;
      
      public:
        Triangle(int hgth,int bs){
            this->height  = hgth;
            this->base    = bs;
        }
        virtual void showDetails();
  };
  
  class ShapeManager{
      public:
        void showDetails(Shape* pShape){
            pShape->showDetails();
        }
  };
#endif
