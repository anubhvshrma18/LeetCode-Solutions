class Solution {
    void seive_algo(vector<bool> &v, int n){
        v[0] = v[1] = false;
        for(int i=2; i*i<n; i++){
            for(int j=2*i; j<n; j+=i){
                v[j] = false;
            }
        }
    }
public:
    bool primeSubOperation(vector<int>& v) {
        vector<bool> isPrime(1005, true);
        seive_algo(isPrime, 1005);

        vector<int> primes;
        for(int i=0; i<1004; i++)
            if(isPrime[i]) primes.push_back(i);
        for(int i = 0; i < v.size(); i += 1) {
            if(i > 0 && v[i] <= v[i - 1]) return false;
            int idx = lower_bound(primes.begin(),primes.end(),v[i]) - primes.begin();
            for(int j = idx - 1; j >= 0; j -= 1) {
                if(i == 0 || v[i] - primes[j] > v[i - 1]) {
                    v[i] -= primes[j];break;
                }
            }
        }
        return true;
    }
};