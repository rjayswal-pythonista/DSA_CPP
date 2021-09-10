#include<iostream>
using namespace std;

// ~0 = -1
// 2^i = 1<<i

int getIthbits(int num, int i) {
    int mask = (1<<i);
    int res = num & mask;
    return (res>0)?1:0;
}

int clearIthbits(int &num, int i) {
    int mask = ~(1<<i);
    return (num & mask);
}

int setIthbits(int &num, int i) {
    int mask = (1<<i);
    return (num | mask);
}

int updateIthbits(int &num, int i, int v) {
    num = clearIthbits(num, i);
    int mask = (v<<i);
    num = (num | mask);
    return num;
}

int clearIbits(int &num, int i) {
    int mask = (-1<<i);
    return (num & mask);
}

int clearBitsInRange(int &num, int i, int j) {
    int mask_a = ((~0)<<(j+1));         // mask_a = set bit upto j from MSB
    int mask_b = (1<<i)-1;          // mask_b = set bit upto i from LSB
    int mask = (mask_a | mask_b);
    return (num & mask);
}

int replaceBitsInRange(int &num, int i, int j, int m) {
    num = clearBitsInRange(num, i, j);
    int mask = (m << i);
    return (num | mask);
}

int oddEvenDetect(int num) {
    if (num & 1){
        return 1;
    } else {
        return 0;
    }
}

int powerOfTwo(int num) {
    if (num & (num - 1)) {
        return 0;
    } else {
        return 1;
    }
}

int countSetBits1(int num) {            // Time Complexity: O(log(N))
    int count = 0;                      // No. of times in for loop for 8 = 3
    while(num>0) {
        count += (num & 1);
        num = (num >> 1);
    }
    return count;
}

int countSetBits2(int num) {            // Fastest Method for Set bit count
    int count = 0;                      // No. of times in for loop for 8 = 1
    while(num>0) {
        num = (num & (num - 1));
        count++;
    }
    return count;
}

int fastExponentiation(int a, int num) {
    int ans=1;
    int last_bit=0;
    while (num > 0) {
        last_bit = (num&1);
        if (last_bit) {
            ans = ans * a;
        }
        a = a * a;
        num = num >> 1;
    }
    return ans;
}

int dec2Binary(int num) {
    int ans = 0;
    int pow = 1;
    int last_bit=0;
    while (num > 0) {
        last_bit = (num & 1);
        ans += last_bit * pow;
        pow = pow * 10;
        num = (num >> 1);
    }
    return ans;
}

int main() {
    int num, i, j, v, k, choice, m;
    v=0;    // To set val for ith bit
    k=1;    // clear last k bits
    bool oper = true;
    while(oper) {
        cout<<"#############################################################################"<<endl;
        cout<<"                 WELCOME TO BIT MANIPULATION PROGRAM                         "<<endl;
        cout<<"#############################################################################"<<endl;
        cout<<"Enter your choice of operations"<<endl;
        cout<<"1. Get ith Bit of Number"<<endl;
        cout<<"2. Clear ith Bit of Number"<<endl;
        cout<<"3. Set the ith Bit of Number"<<endl;
        cout<<"4. Update ith Bit of Number"<<endl;
        cout<<"5. Clear last ith Bit of Number"<<endl;
        cout<<"6. Clear bits in range of two Numbers"<<endl;
        cout<<"7. Replace bits in range of two Numbers"<<endl;
        cout<<"8. Odd Even Detection"<<endl;
        cout<<"9. Detect Power of Two"<<endl;
        cout<<"10. Count number of set bits"<<endl;
        cout<<"11. Decimal to Binary Conversion"<<endl;
        cout<<"12. Quit"<<endl;
        label:
            cout<<"Enter your Operation choice"<<endl;
            cin>>choice;
        if (choice == 12) {
            cout<<"End of Bit Manipulation Program. Thank you!!!"<<endl;
            break;
        }
        if (choice > 12 || choice < 1) {
            cout<<"Invalid User Choice of Operation. Try again"<<endl;
            goto label;
        }
        cout<<"Enter a Number"<<endl;
        cin>>num;
        if (choice < 8) {
            cout<<"Enter the position of ith bit"<<endl;
            cin>>i;
        }
        switch(choice) {
            case 1: cout<<"Result: "<<i<<"th bit is: "<<getIthbits(num, i)<<endl;
                    break;
            case 2: cout<<"Clear the "<<i<<"th bit result: "<<clearIthbits(num, i)<<endl;
                    break;
            case 3: cout<<"Set the "<<i<<"th bit result: "<<setIthbits(num, i)<<endl;
                    break;
            case 4: cout<<"Update the "<<i<<"th bit with "<< v << " result: "<<updateIthbits(num, i, v)<<endl;
                    break;
            case 5: cout<<"Clear "<<i<<" bits result: "<<clearIbits(num, k)<<endl;
                    break;
            case 6: cout<<"Enter the position of jth bit"<<endl;
                    cin>>j;
                    cout<<"Clear bits in range ("<<i<<","<<j<<")"<<" result: "<<clearBitsInRange(num, i, j)<<endl;
                    break;
            case 7: cout<<"Enter the position of jth bit"<<endl;
                    cin>>j;
                    cout<<"Enter number which needs to replaced in original number "<<num<<endl;
                    cin>>m;
                    cout<<"Replace bits in range ("<<i<<","<<j<<")"<<" with "<<m<<" result: "<<replaceBitsInRange(num, i, j, m)<<endl;
                    break;
            case 8: cout<<num<<" is: "<<(oddEvenDetect(num)?"Odd":"even")<<endl;
                    break;
            case 9: cout<<num<<" is "<<(powerOfTwo(num)?"":"NOT ")<<"power of two"<<endl;
                    break;
            case 10: cout<<"Number of set bits in "<<num<<" is "<<countSetBits2(num)<<endl;
                    break;
            case 11: cout<<"Binary equivalent of decimal number "<<num<<" is "<<dec2Binary(num)<<endl;
                    break;
            default: cout<<"Invalid User Choice"<<endl;
                    break;
        }
    }
    return 0;
}