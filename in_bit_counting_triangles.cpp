long long M=1e9+7;
int Solution::nTriang(vector<int> &a) {
    vector<long long>A;
    if(a.size()<3)return 0;
    for(auto i:a)A.push_back(i);
    long long ans=0;
    sort(A.begin(),A.end());
    for(int i=0;i!=A.size();i++){
        //A[i] > A[r] - A[l]
        for(int j=i+1;j<A.size();j++){
            long long req=A[i]+A[j];
            ans+=(lower_bound(A.begin(),A.end(),req)-A.begin())-(j+1);
            //no need to consider from 0 to j
            //as when Ak > Aj, k > j as array is sorted
            ans%=M;
        }
    }
    return ans;
}
