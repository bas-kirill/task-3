#include <vector>
#include <iterator>
#include <utility>
#include <iostream>
#include <sstream> 
#include <locale.h>
#include <ctime>
using namespace std;

typedef vector<double> vec;
typedef vector<vector<double>> vec_2;
vec_2 create_d2(stringstream& lcin,int n,int m) {
    double x;
    vec_2 rez(n,vec(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            double x;
            lcin >> x;
            rez[i][j] = x;
        }
    }
    return rez;
}
vec create_d1(stringstream& lcin) {
    vec rez;
    while (!lcin.eof()) {
        double x;
        lcin >> x;
        rez.push_back(x);
    }
    return rez;
}

vec d2_in_d1(vec_2 rez,int n,int m) {
    vec poz(n*m);
    int i, j;
    auto ipoz = poz.begin();

    for (auto iter = rez.begin(); iter != rez.end(); iter++) {
        i = distance(rez.begin(), iter);
        for (auto it = iter->begin(); it != iter->end(); it++) {

            j = distance(iter->begin(), it);
            ipoz = poz.begin() + m * i + j;
            *(ipoz) = *it;
        }
    }
    
    return poz;
}
vec_2 d1_in_d2(vec rez, int n, int m) {
    vec_2 poz(n, vec(m));
    int i, j;
    auto ipoz = poz.begin();
    
    for (auto iter = rez.begin(); iter != rez.end(); iter++) {
        i = distance(rez.begin(), iter);
        ipoz = poz.begin() + int(i / m);
        vec::iterator it = ipoz->begin() + i % m;
        *(it) = *iter;

    }
    return poz;
}

int main()
{
 
  int summa = 0;
    vec_2 d9(9, vec(9));
    for (auto iter = d9.begin(); iter != d9.end(); iter++) {
					for (auto it = iter->begin(); it != iter->end(); it++) {
                        *it = 1;
					}
					
				}
    for (auto iter = d9.begin(); iter != d9.end(); iter++) {
        for (auto it = iter->begin(); it != iter->end(); it++) {
            cout << *it << " ";
        }
        cout << endl;
        
    }
    for (auto iter = d9.begin(); iter != (d9.begin()+5); iter++) {
        for (auto it = iter->begin()+distance(d9.begin(),iter); it != ((iter->begin()+9)-distance(d9.begin(),iter)); it++) {
            summa += *it;
        }

    }
  
    for (auto iter = (d9.begin()+5); iter != d9.end(); iter++) {
        for (auto it = (iter->begin() + 9 - distance(d9.begin(), iter)-1); it != (iter->begin() + distance(d9.begin(), iter)+1); it++) {
            summa += *it;
        }

    }
    
    
    cout << summa << endl;
 
   
	setlocale(LC_ALL, "Rus");

}
