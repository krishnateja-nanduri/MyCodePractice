//https://www.hackerrank.com/challenges/interval-selection/problem

#include <iostream>
#include <set>

using namespace std;

class Interval{
public:
int begin;int end;
Interval(){
    begin=0;end=0;
}

Interval(int _b,int _e){
    begin=_b;end=_e;
}

 bool operator==(const Interval& i) const {
     return (begin==i.begin)&&(end==i.end);
 }

 bool operator<(const Interval& i) const {
     return begin<i.begin;
 }
};

int n,t,a,b;
multiset<Interval> inters;
multiset<int> iends;

multiset<Interval>::iterator it1;
multiset<int>::iterator et1;

int main(){
cin >> t;
while(t--){
    inters.clear();
    iends.clear();
    cin >> n;
    while(n--){
        cin >> a >> b;
        Interval inter(a,b);
        inters.insert(inter);
    }
    it1=inters.begin();
    while(it1!=inters.end()){
        iends.insert(it1->end);
        et1=iends.lower_bound(it1->begin);
        multiset<int>::iterator t=et1;
        if((++et1!=iends.end())&&(++et1!=iends.end())){
           
            while(et1!=iends.end()){
                multiset<int>::iterator te=et1;
                et1++;
                iends.erase(te);
            }
        }
        it1++;
    }
    cout << iends.size() <<endl;
}

return 0;
}
