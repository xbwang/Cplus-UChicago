#include <vector>
#include <iostream>
using namespace std;

int main(){
	vector<vector<int> > v;
	vector<int> n;
	vector<int> line;
	int i = 0, j = 0;
	
	for(i = 0; i < 8; i++){
		v.push_back(line);
		n.push_back(0);
		for(j = 0; j < 17; j++){
			v[i].push_back(0);
		}
	}
	v[0].at(8) = 1;
	for(i = 1; i < 8; i++){
		for(j = 1; j < 16; j++){
			v[i].at(j) = v[i-1].at(j-1) + v[i-1].at(j+1);
		}
	}
	//print out
	for(i = 0; i < 8; i++){
		vector<int>::iterator it;
		for(it = v[i].begin(); it != v[i].end(); it++){
			if(*it >= 10){
				n.at(i)++;
			}
			n.at(i)++;
		}
	}
	for(i = 0; i < 8; i++){
		vector<int>::iterator it;
		int tmp = (n.at(7) - n.at(i))/2;
		int x = (n.at(7) - n.at(i)) - tmp;
		while(x > 0){
			cout << " ";
			x--;
		}
		for(j = 0; j < 17; j++){
			if(v[i].at(j) != 0){
				cout << v[i].at(j);
			}else{
				cout << " ";
			}
		}
		cout << "\n";
	}
	
	return 0;
}