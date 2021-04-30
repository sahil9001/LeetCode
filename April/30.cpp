class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        vector<int> ans;
        if(x==1 || y==1){
            if(x==1 && y==1){
                if(2<=bound) ans.push_back(2);
            }
            else if(x==1 && y!=1){
                int bb = bound;
                int c = 0;
                while(bb!=0){
                    bb/=y;
                    c++;
                }
                int yy = 1;
                int xx = 1;
                int mul = 1;
                for(int i=0;i<c;i++){
                    if(mul + 1<=bound)
                    ans.push_back(1 + mul);
                    mul *= y;
                }
            }
            else if(y==1 && x!=1){
                int bb = bound;
                int c = 0;
                while(bb!=0){
                    bb/=x;
                    c++;
                }
                int yy = 1;
                int xx = 1;
                int mul = 1;
                for(int i=0;i<c;i++){
                    if(mul + 1<=bound)
                    ans.push_back(1 + mul);
                    mul *= x;
                }
            }
            
        }
        else{
            int bb = bound;
            int c = 0;
            while(bb!=0){
                bb/=x;
                c++;
            }
            bb = bound;
            int c1 = 0;
            while(bb!=0){
                bb/=y;
                c1++;
            }
            int yy = 1;
            int xx = 1;
            int mul = 1;
            for(int i=0;i<c;i++){
                int mul1 = 1;
                for(int j=0;j<c1;j++){
                    if(mul + mul1<=bound)
                        ans.push_back(mul + mul1);
                    mul1 *= y;
                }
                mul *= x;
            }
        }
        sort(ans.begin(),ans.end());
        ans.erase(unique(ans.begin(),ans.end()),ans.end());
        return ans;
    }
};
