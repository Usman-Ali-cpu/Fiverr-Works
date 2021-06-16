#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

struct Item{
    string name;
    unsigned int value;
    Item(string n, unsigned int v){
        this->name = n;
        this->value = v;
    }
    void display(){
        cout<< "Name : " << this->name << endl;
        cout<< "Value : " << this->value<< endl<< endl;
    }
};

// Function to find all unique combination of
// given elements such that their sum is K
void uniqueFiveCombination(int l, int sum, int K, vector<Item>& local,vector<Item>& A){
    static int check = 0;

    // If a unique combination of 5 items is found
    // static int count = 0;
    cout << "Start Sum  : " << sum << endl;
    cout << "Size : " << local.size() << endl;
    if (sum == K && local.size() == 5) {
        sum = 0;
        cout << "{";
		for (int i = 0; i < local.size(); i++)
		{
			if (i != 0)
				cout << " ";
			cout <<local[i].name<< " : " << local[i].value;
			if (i != local.size() - 1)
				cout << ", ";
		}
		cout << "}" << endl;
        // local.clear();
        for (int i = 0; i < 5; i++)
		{
            cout << "Poping " << endl;
            if(local.size()> 0)
                local.pop_back();
        }
        // count = 0;
        // return;
	}

    // if(local.size()== 5 &&  sum+2 != K){
    //     for (int i = 0; i < 5; i++)
	// 	{
    //         cout << "Poping " << endl;
    //         local.pop_back();
    //     }
    //     // sum = 0;
    // }

	// For all other combinations
	for (int i = l; i < A.size(); i++)
	{
        if(sum != K && check== 5){
            for (int i = 0; i < 5; i++){
                cout << " Under Poping " << endl;
                if(local.size()> 0)
                    local.pop_back();
            }    
        }

		// Check if the sum exceeds K
		if (sum + A[i].value > K)
			continue;
		// Check if it is repeated or not
		if (i > l and A[i].value == A[i - 1].value)
			continue;
		// Take the element into the combination
		local.push_back(A[i]);
        // count++;

        if(sum+A[i].value == 0){
            sum += A[i + 1].value;
        }
        // Recursive call
        cout << "ENd Sum  : " << sum << endl;
        
        check++;
        uniqueFiveCombination(i + 1, sum + A[i].value, K, local, A);

		// Remove element from the combination
		// local.pop_back();
        // count--;
    }
}

void sort(vector<Item> & s){
    for (int i = 0; i < s.size(); i++){
        int v = s[i].value;
        for (int j = i; j < s.size(); j++){
            if(s[i].value > s[j].value){
                string name = s[i].name;
                s[i].name = s[j].name;
                s[j].name = name;
                s[i].value = s[i].value + s[j].value;
                s[j].value = s[i].value - s[j].value;
                s[i].value = s[i].value - s[j].value;
            }
        }
    }
}

// Function to find all combination
// of the given elements
void Combination(vector<Item> A, int SUM)
{
	// Sort the given elements
	sort(A);
	// To store combination
	vector<Item> local;

	uniqueFiveCombination(0, 0, SUM, local, A);
}



int main(){

    vector<Item> vect;
    for (int i = 0; i < 50; i++){
        string s = "name" + to_string(i + 1);
        Item item(s, (i+1)*2 );
        vect.push_back(item);
    }
    // Item ite("namelat", 24);
    // vect.push_back(ite);

    int SUM = 22;

    cout << "\n\t*********** WORKING ***********\n" << endl;

    cout << "\n\t*********** RESULTS ***********\n" << endl;

    // Function call
    Combination(vect, SUM);

    cout << "\n\t*********** COMPLETED ***********\n" << endl;

    return 0;
}