#include<bits/stdc++.h>
using namespace std;
class DividedByZeroException {};
class Int {
   private:
       vector<char> digits;
       bool sign;
       void trim();
   public:
       Int(int);
       Int(string&) ;
       Int();
       Int(const Int&);
       Int operator=(const Int& op2);
       Int abs() const;
       Int pow(int a);
       friend Int operator+=(Int&, const Int&);
       friend Int operator-=(Int&, const Int&);
       friend Int operator*=(Int&, const Int&);
       friend Int operator/=(Int&, const Int&) throw(DividedByZeroException);
       friend Int operator%=(Int&, const Int&) throw(DividedByZeroException);
       friend Int operator+(const Int&, const Int&);
       friend Int operator-(const Int&, const Int&);
       friend Int operator*(const Int&, const Int&);
       friend Int operator/(const Int&, const Int&) throw(DividedByZeroException);
       friend Int operator%(const Int&, const Int&) throw(DividedByZeroException);
       friend Int operator-(const Int&);
       friend Int operator++(Int&);
       friend Int operator++(Int&, int);
       friend Int operator--(Int&);
       friend Int operator--(Int&, int);
       friend bool operator>(const Int&, const Int&);
       friend bool operator<(const Int&, const Int&);
       friend bool operator==(const Int&, const Int&);
       friend bool operator!=(const Int&, const Int&);
       friend bool operator>=(const Int&, const Int&);
       friend bool operator<=(const Int&, const Int&);
       friend ostream& operator<<(ostream&, const Int&);
       friend istream& operator>>(istream&, Int&);
   public:
       static const Int ZERO;
       static const Int ONE;
       static const Int TEN;
};
const Int Int::ZERO = Int(0);
const Int Int::ONE = Int(1);
const Int Int::TEN = Int(10);
Int::Int() {
   sign = true;
}
Int::Int(int val) {
   if (val >= 0) {
       sign = true;
   }
   else {
       sign = false;
       val *= (-1);
   }
   do {
       digits.push_back((char)(val % 10));
       val /= 10;
   } while (val != 0);
}
Int::Int(string& def) {
   sign = true;
   for (string::reverse_iterator iter = def.rbegin() ; iter < def.rend();  iter++) {
       char ch = (*iter);
       if (iter == def.rend() - 1) {
           if (ch == '+') {
               break;
           }
           if (ch == '-') {
               sign = false;
               break;
           }
       }
       digits.push_back((char)((*iter) - '0'));
   }
   trim();
}
void Int::trim() {
   vector<char>::reverse_iterator iter = digits.rbegin();
   while (!digits.empty() && (*iter) == 0) {
       digits.pop_back();
       iter = digits.rbegin();
   }
   if (digits.size() == 0) {
       sign = true;
       digits.push_back(0);
   }
}
Int::Int(const Int& op2) {
   sign = op2.sign;
   digits = op2.digits;
}
Int Int::operator=(const Int& op2) {
   digits = op2.digits;
   sign = op2.sign;
   return (*this);
}
Int Int::abs() const {
   if (sign) {
       return *this;
   }
   else {
       return -(*this);
   }
}
Int Int::pow(int a) {
   Int res(1);
   for (int i = 0; i < a; i++) {
       res *= (*this);
   }
   return res;
}
Int operator+=(Int& op1, const Int& op2) {
   if (op1.sign == op2.sign) {
       vector<char>::iterator iter1;
       vector<char>::const_iterator iter2;
       iter1 = op1.digits.begin();
       iter2 = op2.digits.begin();
       char to_add = 0;
       while (iter1 != op1.digits.end() && iter2 != op2.digits.end()) {
           (*iter1) = (*iter1) + (*iter2) + to_add;
           to_add = ((*iter1) > 9);
           (*iter1) = (*iter1) % 10;
           iter1++;
           iter2++;
       }
       while (iter1 != op1.digits.end()) {
           (*iter1) = (*iter1) + to_add;
           to_add = ((*iter1) > 9);
           (*iter1) %= 10;
           iter1++;
       }
       while (iter2 != op2.digits.end()) {
           char val = (*iter2) + to_add;
           to_add = (val > 9) ;
           val %= 10;
           op1.digits.push_back(val);
           iter2++;
       }
       if (to_add != 0) {
           op1.digits.push_back(to_add);
       }
       return op1;
   }
   else {
       if (op1.sign) {
           return op1 -= (-op2);
       }
       else {
           return op1 = op2 - (-op1);
       }
   }
}
Int operator-=(Int& op1, const Int& op2) {
   if (op1.sign == op2.sign) {
       if (op1.sign) {
           if (op1 < op2) {
               return  op1 = -(op2 - op1);
           }
       }
       else {
           if (-op1 > -op2) {
               return op1 = -((-op1) - (-op2));
           }
           else {
               return op1 = (-op2) - (-op1);
           }
       }
       vector<char>::iterator iter1;
       vector<char>::const_iterator iter2;
       iter1 = op1.digits.begin();
       iter2 = op2.digits.begin();
       char to_substract = 0;
       while (iter1 != op1.digits.end() && iter2 != op2.digits.end()) {
           (*iter1) = (*iter1) - (*iter2) - to_substract;
           to_substract = 0;
           if ((*iter1) < 0) {
               to_substract = 1;
               (*iter1) += 10;
           }
           iter1++;
           iter2++;
       }
       while (iter1 != op1.digits.end()) {
           (*iter1) = (*iter1) - to_substract;
           to_substract = 0;
           if ((*iter1) < 0) {
               to_substract = 1;
               (*iter1) += 10;
           }
           else {
               break;
           }
           iter1++;
       }
       op1.trim();
       return op1;
   }
   else {
       if (op1 > Int::ZERO) {
           return op1 += (-op2);
       }
       else {
           return op1 = -(op2 + (-op1));
       }
   }
}
Int operator*=(Int& op1, const Int& op2) {
   Int result(0);
   if (op1 == Int::ZERO || op2 == Int::ZERO) {
       result = Int::ZERO;
   }
   else {
       vector<char>::const_iterator iter2 = op2.digits.begin();
       while (iter2 != op2.digits.end()) {
           if (*iter2 != 0) {
               deque<char> temp(op1.digits.begin(), op1.digits.end());
               char to_add = 0;
               deque<char>::iterator iter1 = temp.begin();
               while (iter1 != temp.end()) {
                   (*iter1) *= (*iter2);
                   (*iter1) += to_add;
                   to_add = (*iter1) / 10;
                   (*iter1) %= 10;
                   iter1++;
               }
               if (to_add != 0) {
                   temp.push_back(to_add);
               }
               int num_of_zeros = iter2 - op2.digits.begin();
               while (num_of_zeros--) {
                   temp.push_front(0);
               }
               Int temp2;
               temp2.digits.insert(temp2.digits.end(), temp.begin(), temp.end());
               temp2.trim();
               result = result + temp2;
           }
           iter2++;
       }
       result.sign = ((op1.sign && op2.sign) || (!op1.sign && !op2.sign));
   }
   op1 = result;
   return op1;
}
Int operator/=(Int& op1, const Int& op2) throw(DividedByZeroException) {
   if (op2 == Int::ZERO) {
       throw DividedByZeroException();
   }
   Int t1 = op1.abs(), t2 = op2.abs();
   if (t1 < t2) {
       op1 = Int::ZERO;
       return op1;
   }
   deque<char> temp;
   vector<char>::reverse_iterator iter = t1.digits.rbegin();
   Int temp2(0);
   while (iter != t1.digits.rend()) {
       temp2 = temp2 * Int::TEN + Int((int)(*iter));
       char s = 0;
       while (temp2 >= t2) {
           temp2 = temp2 - t2;
           s = s + 1;
       }
       temp.push_front(s);
       iter++;
   }
   op1.digits.clear();
   op1.digits.insert(op1.digits.end(), temp.begin(), temp.end());
   op1.trim();
   op1.sign = ((op1.sign && op2.sign) || (!op1.sign && !op2.sign));
   return op1;
}
Int operator%=(Int& op1, const Int& op2) throw(DividedByZeroException) {
   return op1 -= ((op1 / op2) * op2);
}
Int operator+(const Int& op1, const Int& op2) {
   Int temp(op1);
   temp += op2;
   return temp;
}
Int operator-(const Int& op1, const Int& op2) {
   Int temp(op1);
   temp -= op2;
   return temp;
}
Int operator*(const Int& op1, const Int& op2) {
   Int temp(op1);
   temp *= op2;
   return temp;

}
Int operator/(const Int& op1, const Int& op2) throw(DividedByZeroException) {
   Int temp(op1);
   temp /= op2;
   return temp;
}
Int operator%(const Int& op1, const Int& op2) throw(DividedByZeroException) {
   Int temp(op1);
   temp %= op2;
   return temp;
}
Int operator-(const Int& op) {
   Int temp = Int(op);
   temp.sign = !temp.sign;
   return temp;
}
Int operator++(Int& op) {
   op += Int::ONE;
   return op;
}
Int operator++(Int& op, int x) {
   Int temp(op);
   ++op;
   return temp;
}
Int operator--(Int& op) {
   op -=  Int::ONE;
   return op;
}
Int operator--(Int& op, int x) {
   Int temp(op);
   --op;
   return temp;
}
bool operator<(const Int& op1, const Int& op2) {
   if (op1.sign != op2.sign) {
       return !op1.sign;
   }
   else {
       if (op1.digits.size() != op2.digits.size())
           return (op1.sign && op1.digits.size() < op2.digits.size())
               || (!op1.sign && op1.digits.size() > op2.digits.size());
       vector<char>::const_reverse_iterator iter1, iter2;
       iter1 = op1.digits.rbegin();
       iter2 = op2.digits.rbegin();
       while (iter1 != op1.digits.rend()) {
           if (op1.sign &&  *iter1 < *iter2) {
               return true;
           }
           if (op1.sign &&  *iter1 > *iter2) {
               return false;
           }
           if (!op1.sign &&  *iter1 > *iter2) {
               return true;
           }
           if (!op1.sign &&  *iter1 < *iter2) {
               return false;
           }
           iter1++;
           iter2++;
       }
       return false;
   }
}
bool operator==(const Int& op1, const Int& op2) {
   if (op1.sign != op2.sign  || op1.digits.size() != op2.digits.size()) {
       return false;
   }
   vector<char>::const_iterator iter1, iter2;
   iter1 = op1.digits.begin();
   iter2 = op2.digits.begin();
   while (iter1 != op1.digits.end()) {
       if (*iter1 != *iter2) {
           return false;
       }
       iter1++;
       iter2++;
   }
   return true;
}
bool operator!=(const Int& op1, const Int& op2) {
   return !(op1 == op2);
}
bool operator>=(const Int& op1, const Int& op2) {
   return (op1 > op2) || (op1 == op2);
}
bool operator<=(const Int& op1, const Int& op2) {
   return (op1 < op2) || (op1 == op2);
}
bool operator>(const Int& op1, const Int& op2) {
   return !(op1 <= op2);
}
ostream& operator<<(ostream& stream, const Int& val) {
   if (!val.sign) {
       stream << "-";
   }
   for (vector<char>::const_reverse_iterator iter = val.digits.rbegin(); iter != val.digits.rend() ; iter++) {
       stream << (char)((*iter) + '0');
   }
   return stream;
}
istream& operator>>(istream& stream, Int& val) {
   string str;
   stream >> str; 
   val = Int(str);
   return stream;
}

