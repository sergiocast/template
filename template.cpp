#include <iostream>
#include <vector>
#include <list>
#include <typeinfo>


//The program creates a mySum template function which, if passed with a container of int or double, returns the sum
//but when passed with a vector of std::string, returns the total number of characters of all elements.
//The program is tested with containers of int, double and string in the main function

using namespace std;


template<typename X, typename Y>
struct SameType
{
   enum { result = 0 };
};

template<typename T>
struct SameType<T, T>
{
   enum { result = 1 };
};



template <typename T, typename S>


S mySum(T first, T last, S sum){

    vector<int>::iterator it;

	for(auto it = first; it != last; it++){

		sum += *it;

	}


 static_assert(SameType<T, vector<int>::iterator> ::result ==1
		 || SameType<T, list<double>::iterator> ::result ==1
		 || SameType<T, list<int>::iterator> ::result ==1
		 || SameType<T, vector<double>::iterator> ::result ==1, "Error");


 static_assert(SameType<typename iterator_traits<T>::value_type, S> ::result ==1 , "Error");


  return sum;


}


template <typename T>

bool is_addable(T a){


if ((SameType<T, vector<int>::iterator> ::result ==1) || (SameType<T, vector<double>::iterator> ::result ==1)
	||(SameType<T, list<int>::iterator> ::result ==1) || (SameType<T, list<double>::iterator> ::result ==1))
	{
	   return true;
	}
	else
	{
	   return false;
	}

}



 template<>

int mySum(vector<string>::iterator first, vector<string>::iterator last, int sum){

    vector<string>::iterator it;


     for(auto it = first; it != last; it++){

   	  string g = *it;
         int y = g.size();

   	  sum+= y;

   	}


      return sum;

}




int main(){


vector<int> v1 = {1, 2, 3, 4};

int sum1 =1;

int z = mySum(v1.begin(),v1.end(), sum1);

cout<<"Sum of v1: " << z <<endl;


/////////////////////////////////////////


list<double> v2 = {1.1, 2.2, 3.3, 4.4};

double sum2 = 1.2;

double d = mySum(v2.begin(),v2.end(), sum2);

cout<<"Sum of v2: " << d <<endl;




//////////////////////////////////

vector<std::string> v3 = {"Hello", "world", "Yes", "No"};


int sum3 = 0;

int p = mySum(v3.begin(),v3.end(), sum3);

cout<<"Sum of v3: " << p <<endl;

////////////////////////////////////////




//list<std::string> v4 = {"Yes", "No"};

//float wrong_init = 0.0;

//cout << mySum(v4.begin(), v4.end(), 0) << endl;
//cout << mySum(v1.begin(), v1.end(), wrong_init) << endl;





}
