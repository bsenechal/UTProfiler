#ifndef SINGLETON_H
#define SINGLETON_H

#include <iostream>

template <typename T>
class Singleton
{

public:
  static T *getInstance ()
  {
    if (NULL == _singleton)
      {
        std::cout << "Creation du singleton." << std::endl;
        _singleton = new T;
      }
    else
      {
        std::cout << "Le singleton existe deja !" << std::endl;
      }

    return (static_cast<T*> (_singleton));
  }



  static void kill ()
  {
    if (NULL != _singleton)
      {
        delete _singleton;
        _singleton = NULL;
      }
  }

protected:
  static T *_singleton;

private:
        T& operator= (const T&){}

};

template <typename T> T *Singleton<T>::_singleton = NULL;


#endif // SINGLETON_H
