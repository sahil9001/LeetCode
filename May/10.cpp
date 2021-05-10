class Solution {
    private:
        bool isprime[5000001];
    public:
    int calc(int n){
        for(int i=2;i<5000001;i++)
            isprime[i] = false;
        for(int i=2;i<5000001;i++){
            if(!isprime[i]){
                for(int j=2*i;j<5000001;j+=i){
                    isprime[j] = true;
                }
            }
        }
        int c = 0;
        for(int i=2;i<n;i++){
            if(isprime[i]==false) c++;
        }
        return c;
    }
    int countPrimes(int n) {
        return calc(n);
    }
};
