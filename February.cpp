#include <bits/stdc++.h>
#include <boost/math/common_factor.hpp>
#include<math.h>
//jnjnjnjnjn
using namespace std;
long long  modexp(long long x, long long n)
{ long long m=1000000007;
	if (n == 0) {
		return 1;
	}
	else if (n % 2 == 0) {
		return modexp((x * x) % m, n / 2);
	}
	else {
		return (x * modexp((x * x) % m, (n - 1) / 2) % m);
	}
}
long long getFractionModulo(long long a, long long b)
{  long long m=1000000007;
	long long c = __gcd(a, b);
	a = a / c;
	b = b / c;
	long long d = modexp(b, m - 2);
	long long ans = ((a % m) * (d % m)) % m;
    return ans;
}
int main()
{
    long long t;
    cin>>t;
    while(t--){

        long long k,m,i,n1,lcm,p,q,z;
        long long flag=0;
        long long m1=1000000007;

        cin>>n1>>k>>m;
        if(m==1){
	    long long a = 1, b = n1;
	    cout << getFractionModulo(a, b)%m1 << endl;
        }
        else if(m>=2){
        for(i=1;i<=m;i++){
                if(n1>k && m%2!=0){
                    n1=n1%k;
                    for(j=1;j<=m/2;j++){
                        p=pow(n1,m/2-i);
                        p=p*(n1+k);
                        p=p*pow(n1-1,i-1);
                    }
                    q=pow(n1,m/2)*n1+k;
                }
        }cout<<getFractionModulo(p, q)%m1<<endl;
        }
    }
}
