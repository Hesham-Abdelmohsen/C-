#include <iostream>
#include <bits/stdc++.h>
#include <sstream>


using namespace std;

class  BigDecimalInt {

    public:
        string digit1;

    public:

        BigDecimalInt(int number){

            stringstream ss;
            ss<<number;
            ss>>digit1;
        }


        BigDecimalInt(string number){
            digit1 = number;
        }

        ///*************************************************///
        ///compare negative VS positive
        /// ensure s1 > s2
        bool compare(string s1, string s2){
            if(s1.length()>s2.length())
                return true;
            else if(s1.length()==s2.length() ){
                if(isSmaller(s2,s1))
                    return true;
            }
            else
                return false;
        }


        string findSum(string str1, string str2)
{

    if(str1[0]=='-' && str2[0] != '-'){


            str1.erase(str1.begin());

            if(compare(str1,str2))
                return '-'+ findDiff( str1,  str2);


            return findDiff( str1,  str2);
    }

     if(str2[0]=='-' && str1[0] !='-'){

            str2.erase(str2.begin());

            if(compare(str2,str1))
                return '-'+ findDiff( str1,  str2);

            return findDiff( str1,  str2);
    }


    if(str1[0]=='-' && str2[0]=='-'){

            str1.erase(str1.begin());
            str2.erase(str2.begin());
            return '-' +internal_Sum(str1,str2);

    }

    else

        return internal_Sum(str1,str2);

}

string internal_Sum(string str1, string str2){


	/// Before proceeding further, make sure length
	/// of str2 is larger.
	if (str1.length() > str2.length())
		swap(str1, str2);

	/// Take an empty string for storing result
	string str = "";

	int n1 = str1.length(), n2 = str2.length();
	int diff = n2 - n1;

	int carry = 0;

	/// Traverse from end of both strings
	for (int i=n1-1; i>=0; i--)
	{
		int sum = ((str1[i]-'0') + (str2[i+diff]-'0') + carry);

		str.push_back(sum%10 + '0');/// ascii code

		carry = sum/10;
	}


	/// Add remaining digits of str2[]

	for (int i=n2-n1-1; i>=0; i--)
	{
		int sum = ((str2[i]-'0')+carry);
		str.push_back(sum%10 + '0');
		carry = sum/10;
	}

	/// Add remaining carry
	if (carry)
		str.push_back(carry+'0');

	/// reverse result string
	reverse(str.begin(), str.end());

	return str;

}

///*************************************************///
///*************************************************///


/// Returns true if str1 is smaller than str2,
/// else false.
bool isSmaller(string str1, string str2)
{
	int n1 = str1.length(), n2 = str2.length();

	if (n1 < n2)
		return true;
	if (n2 > n1)
		return false;

	for (int i=0; i<n1; i++)
	{
		if (str1[i] < str2[i])
			return true;
		else if (str1[i] > str2[i])
			return false;
	}
	return false;
}


string subtract(string s1 , string s2){

    if(s1[0] != '-' && s2[0] != '-'){
        if(isSmaller(s1,s2))
            return '-'+findDiff(s1,s2) ;
        else
            return findDiff(s1,s2);
    }

    else if(s1[0] == '-' && s2[0] != '-'){

        s1.erase(s1.begin());
        return '-'+findSum(s1,s2);
        }

    else if(s1[0] == '-' && s2[0] == '-')
    {

        s2.erase(s2.begin());
        return findSum(s1,s2);
    }

    else if(s1[0] != '-' && s2[0] == '-'){
        s2.erase(s2.begin());
        return findSum(s2,s1) ;
    }

}




/// Function for finding difference of larger numbers
string findDiff(string str1, string str2)
{
	/// Before proceeding further, make sure str1
	/// is not smaller
	if (isSmaller(str1, str2)){
		swap(str1, str2);
	}

	string str = "";

	int n1 = str1.length(), n2 = str2.length();
	int diff = n1 - n2;

	int carry = 0;

	for (int i=n2-1; i>=0; i--)
	{
		int sub = ((str1[i+diff]-'0') -
				(str2[i]-'0') -
				carry);
		if (sub < 0)
		{
			sub = sub+10;
			carry = 1;
		}
		else
			carry = 0;

		str.push_back(sub + '0');
	}

	/// subtract remaining digits of str1[]
	for (int i=n1-n2-1; i>=0; i--)
	{
		if (str1[i]=='0' && carry)
		{
			str.push_back('9');
			continue;
		}
		int sub = ((str1[i]-'0') - carry);
		if (i>0 || sub>0) /// remove preceding 0's
			str.push_back(sub+'0');
		carry = 0;

	}

	reverse(str.begin(), str.end());

	return str;
}


    friend BigDecimalInt operator+(BigDecimalInt&, BigDecimalInt&);
    friend BigDecimalInt operator-(BigDecimalInt&, BigDecimalInt&);

    void operator = (BigDecimalInt& b2){
            this->digit1 = b2.digit1;
    }

    friend ostream &operator<<( ostream &output, const BigDecimalInt &b ) {
         output << b.digit1 ;
         return output;
      }

        void size(){
                cout<<digit1.size();
        }

};

BigDecimalInt operator + (BigDecimalInt& b1, BigDecimalInt& b2) /// Call by reference
{
    BigDecimalInt b3("");

    b3.digit1 = b3.findSum(b1.digit1,  b2.digit1);

    return b3;
}

BigDecimalInt operator - (BigDecimalInt& b1, BigDecimalInt& b2)
{
    BigDecimalInt b3("");
    b3.digit1 = b3.subtract(b1.digit1,  b2.digit1);
    return b3;
}



int main()
{
    ///add + and +

    BigDecimalInt obj1(500);
    BigDecimalInt obj2(1000);
    BigDecimalInt sum = obj1+obj2 ;  /// operator overloading for =

    cout<<sum<<endl;

    ///add - and +

    BigDecimalInt obj3(-500);
    BigDecimalInt obj4(1000);
    cout<<obj3+obj4<<endl;

    ///add - and +

    BigDecimalInt obj0(-1005);
    BigDecimalInt obj11(-1000);
    BigDecimalInt obj9(1000);
    cout<<obj0+obj9<<endl;
    cout<<obj11+obj9<<endl;

    ///add + and -

    BigDecimalInt obj5(500);
    BigDecimalInt obj6(-1000);
    cout<<obj5+obj6<<endl;

    ///add - and -

    BigDecimalInt obj7(-500);
    BigDecimalInt obj8(-1000);
    cout<<obj7+obj8<<endl;

///*****************************************************///

    /// sub - and -

    BigDecimalInt x(2000); /// > < =
    BigDecimalInt y(1000);
    BigDecimalInt z(2000);
    cout<<x-y<<endl;
    cout<<y-x<<endl;
    cout<<x-z<<endl;

    /// sub + and -

    BigDecimalInt n(2000); /// > < =
    BigDecimalInt m(-1000);
    cout<<n-m<<endl;
    cout<<m-n<<endl;

    BigDecimalInt v(-2000); /// > < =
    BigDecimalInt d(-1000);
    cout<<v-d<<endl;
    cout<<d-v<<endl;

    return 0;
}
