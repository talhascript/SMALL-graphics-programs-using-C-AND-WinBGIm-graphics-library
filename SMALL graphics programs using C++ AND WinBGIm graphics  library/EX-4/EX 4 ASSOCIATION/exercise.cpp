// ? Exercise 4: Association, Aggregation & Composition

// Programming Technique II
// Semester 1, 2021/2022

// Date: 1 January 2021
// Section: _________
// Member 1's Name: _____________    Location: ____________ (i.e. where are you currently located)
// Member 2's Name: _____________    Location: ____________

// Log the time(s) your pair programming sessions
//  Date         Time (From)   To             Duration (in minutes)
//  _________    ___________   ___________    ________
//  _________    ___________   ___________    ________
//  _________    ___________   ___________    ________

#include <iostream>
#include <cmath>
using namespace std;

class Term
{
private:
    int coef;
    int exp;

public:
    Term(int c = 0, int e = 0);
    void set(int c, int e);
    int evaluate(int x) const;
    int exponent() const;
    int coefficient() const;
};
#define MAX 5
class Polynomial
{
private:
    int n; // number of termns
    Term term[MAX];
public:
    Polynomial(int);
    void input();
    int evaluate(int x) const;
    Term largestTerm() const;
    int degree() const;

    int getN() const;
    void setN(int);
};

//----------------------------------------------------------------------------
int main()
{   int n;
    cout<<"Enter a polynomial : \n";
    cout<<"How many terms? => ";
    cin>>n;
    Polynomial p(n);
    p.input();
    cout << endl;

    cout << "Polynomial's degree = " <<p.degree()<< endl;
         

    cout << " x  \t\tPolynomial value" << endl;
    cout << "----\t\t----------------" << endl;

    for (int x = 0; x <= 5; x++)
        cout << x << "  \t\t"<<p.evaluate(x)<< endl;

    cout << endl;

    system("pause");
    return 0;
}

//----------------------------------------------------------------------------
// class Term

// The constructor is given

Term::Term(int c, int e) : coef(c), exp(e) {}

// Implement the other methods
void Term::set(int c, int e) {
    coef = c;
    exp = e;
}
int Term::exponent() const {
    return exp;
}
int Term::coefficient() const {
    return coef;
}
int Term::evaluate(int x) const {
    return coef * pow(x, exp);
}
//----------------------------------------------------------------------------

// class Polynomial

// Implement the constructor and the other methods of the class Polynomial
Polynomial::Polynomial(int _n){
    n=_n;
}

int Polynomial:: getN() const{
    return n;
}

void Polynomial:: setN(int value){
    n = value;
}

void Polynomial::input(){
    int c,e;
    cout<<endl;
    for(int i=0; i<n; i++){
        cout<<"Enter the term #"<<n+1<<" (coef and exp) => ";
        cin>>c>>e;
        term[i].set(c,e);
}}

int Polynomial::evaluate(int x) const{
    int sum = 0;
        for(int i=0; i<n; i++){
            sum = sum + term[i].evaluate(x);
        }
        return sum;
}

int Polynomial::degree() const{
    int largest= term[0].exponent();
       int lindex;
       for(int i=0;i<n;i++){
            if(term[i].exponent() > largest){
                largest = term[i].exponent();
            }
            
        }
        return largest;
}

Term Polynomial:: largestTerm() const{
      int largest= term[0].exponent();
        int lindex;
        for(int i=0;i<n;i++){
            if(term[i].exponent() > largest){
                largest = term[i].exponent();
                lindex = i;
            }
           
        }
     return term[lindex];
    

}

