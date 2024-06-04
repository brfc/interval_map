#include<iostream>
#include<interval_map.hpp>
#include<rapidcheck.h>

bool canonical(const interval_map<int,char>& im)
{

  auto m = im.m_map;
  for(auto it = m.begin() ; it != m.end() ; it++){
    //im.show();
    auto next = it;
    
    next++;
    
    if (m.end() == next) return true;
    
    auto v  = it->second;
    auto nv = next->second;
    if (v == nv){
      RC_LOG(im.show());
      return false;
    }
  }

  return true;
};

const int N = 4;
void check_properties()
{  
  rc::check("keys are canonical",
      [](const std::array<int,N> start_keys, 
         const std::array<int,N> end_keys,
         const std::array<char,N> values) 
  {
    auto m = interval_map<int,char>('x');
          
    for(int i = 0 ; i<N ; i++) {
      m.assign(start_keys[i], end_keys[i], values[i]); 
    }
    RC_LOG(m.show()); 


    RC_ASSERT(canonical(m));
  });
}

int main()
{
  check_properties();
  return 0;
}
