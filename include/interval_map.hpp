
#include <iostream>
#include <list>
#include <string>
#include <sstream>
/* start solution block */


#include <map>
template<typename K, typename V>
class interval_map {
  public:
  friend void IntervalMapTest();
	V m_valBegin;
	std::map<K,V> m_map;
	interval_map(V const& val)
	: m_valBegin(val)
	{}

  void assign(K const& keyBegin, K const& keyEnd, V const& val) {
    if (!(keyBegin < keyEnd)) return;
    if (m_map.size() == 0) {
      m_map.insert({keyBegin, val});
      m_map.insert({keyEnd, m_valBegin});
      return;
    }

    auto itB = m_map.lower_bound(keyBegin);
    auto itE = m_map.lower_bound(keyEnd);

    std::pair<K,V> begin;
    std::pair<K,V> end;
    bool write_begin = true;
    bool write_end = false;   

    begin = {keyBegin, val};

    if(itB != m_map.begin()) {
      auto prev = itB;
      prev--;
        if(prev->second == val) {
          write_begin = false;
        } 
    }
    
    if(itE != m_map.begin()) {
      auto prev = itE; 
      prev--;
      if(itE == m_map.end()) {
        write_end = true;
        end = {keyEnd, m_valBegin};
      } else if( itE->first > keyEnd && prev->second != val)
      {
        write_end = true;
        end = {keyEnd, prev->second};
      }
    } else if(itE->first == keyEnd) { itE++; }

    m_map.erase(itB, itE);
    if(write_end) m_map.insert(end);
    if(write_begin) m_map.insert(begin);
  }

	V const& operator[]( K const& key ) const {
		auto it=m_map.upper_bound(key);
		if(it==m_map.begin()) {
			return m_valBegin;
		} else {
			return (--it)->second;
		}
	}
};
