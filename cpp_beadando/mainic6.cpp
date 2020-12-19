// A map_array_util osztály template, ami
// a map, mint asszociatív tömb tömbként való kezelésére használható.
// Létrehozáskor megadjuk, hogy melyik mappel fog dolgozni, equals-szal
// összehasonlítjuk a paraméterként kapott C tömb elemeivel: ha az értékek
// ugyanazok ugyanabban a sorrendben, akkor igazat ad vissza a kulcsoktól
// függetlenül. A copy a paraméterként kapott tömb elemeit másolja a map
// értékeibe (a tömb és a map elemszámának minimumáig). A swap-pel hasonlóan
// az elemek felcserélhetőek a tömb és map között. A permutation permutáció
// vizsgálatot végez. Legyen olyan értékadás, ahol a jobb oldali
// operandus egy tömb és működjön tetszőleges rendezésű mappel. 

#include <iostream>
#include "maparray.h"
#include <string>
#include <functional>
#include <algorithm>
#include "maparray.h"
#include <map>

struct string_size_less
{

  bool operator()( const std::string& a, const std::string& b ) const
  {
    return a.size() < b.size();
  }

};

const int max = 1000;

bool check()
{
  std::map<int, int> b;
  int v[ max ];
  for( int i = 1; i <= max; ++i )
  {
    b[ i * 2 ] = i;
    v[ i - 1 ] = i;
  }
  const map_array_util<int, int> ut( b );

  std::map<std::string, int> s;
  s[ "C++" ] = 1;
  s[ "Python" ] = 2;
  map_array_util<std::string, int> uls( s );


  std::map<int, std::string> a;
  a[ 5 ]; a[ 1 ]; a[ 2 ];
  std::string msg[] = { "I", "<3", "C++" };
  map_array_util<int, std::string> um( a );
  um.copy( msg, sizeof( msg ) / sizeof( msg[ 0 ] ) );

  if ( !ut.equals( v, max ) || uls.equals( v, max ) || 3 != a.size() ||
       !um.equals( msg, sizeof( msg ) / sizeof( msg[ 0 ] ) ) ||
       "C++" != a[ 5 ] || 0 != a.count( 0 )  || 0 != a.count( 3 ) )
  {
    return false;
  }

  int na[] = {3, 7};
  uls.swap( na, sizeof( na ) / sizeof( na[ 0 ] ) );

  std::swap( v[ 0 ], v[ 1 ] );
  std::swap( v[ 0 ], v[ max / 2 ] );

  if ( ut.permutation( na, sizeof( na ) / sizeof( na[ 0 ] ) ||
       !uls.equals( na, sizeof( na ) / sizeof( na[ 0 ] ) ) ||
       2 != s.size() ) || 7 != s[ "Python" ] ||
       ut.equals( v, max ) || !ut.permutation( v, max ) )
  {
    return false;
  }
  
  std::map<std::string, std::string, string_size_less> ml;
  ml[ "C++" ] = ":-)";
  ml[ "Cobol" ] = ":-S";
  map_array_util<std::string, std::string, string_size_less> mlu( ml );

  std::string e[] = { ":-D", ":-(", ":-/" };
  mlu = e;

  std::map<int, double, std::greater<int> > mg;
  mg[ 2 ] = 3.3;
  mg[ 5 ] = 8.3;
  mg[ 1 ] = 3.9;
  mg[ 7 ] = 8.8;
  map_array_util<int, double, std::greater<int> > mgu( mg );
  double d[] = { 7.3, 9.2 };
  mgu = d;

  return ( 7.8 >  mg.begin()->second && 8.6 < mg[ 5 ] &&
        ":-(" == ml[ "Forth" ] && ":-D" == ml[ "Ada" ] );
}

int main()
{
  std::cout
    << "Your solution is " << (check() ? "" : "not ")
    << "ready for submission.\n";
}
