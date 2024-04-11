class Solution {
public:
    int maximum69Number (int num) {
        int position=-1;
        int positionSX=0;
        int temp=num;
        while(temp>0)
        {
            int lastDigit=temp%10;
            if(lastDigit==6)
            {
                position=positionSX;
            }
            temp=temp/10;
            positionSX++;
            
        }
        if(position==-1)   //we never got 6
            return num;
        else{
            int s=num + 3*pow(10,position);
            return s;
        }
        
    }
};