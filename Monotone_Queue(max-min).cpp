 Monotone queue



1.Finding first minimum number from a position to left and right ( problem solved -- loj Histogram ) 

//template1



    int left_min[mxn];
    int right_min[mxn];

    memset(left_min,0,sizeof left_min);
    memset(right_min,0,sizeof right_min);

    stack<pii>s; // it will store the elements in decreasing order
    
    //finding the first minimum from a position to the left

    for(int i=1;i<=n;i++){
        if(s.empty()){
            s.push({arr[i],i});
            left_min[i]=0;
        }
        else{
            int x = arr[i];
            while(s.size()>0 &&  s.top().first>=x){
                 s.pop();
            }

            if(s.empty()){
                left_min[i]=0;
            }
            else{
                left_min[i]=s.top().second;
            }
            s.push({x,i});
        }
    }


    stack<pii>s2;  // it will store the elements in decreasing order

    //finding the first minimum from a position to the right

    for(int i=n;i>=1;i--){
        if(s2.empty()){
            s2.push({arr[i],i});
            right_min[i]=n+1;
        }
        else{
            int x = arr[i];
            while(s2.size()>0 &&  s2.top().first>=x){
                 s2.pop();
            }

            if(s2.empty()){
                right_min[i]=n+1;
            }
            else{
                right_min[i]=s2.top().second;
            }
            s2.push({x,i});
        }
    }


//template1 ends here

...........................



2.Finding first maximum number from a position to left and right 


//template2


 int left_max[mxn];
    int right_max[mxn];
    memset(left_max,0,sizeof left_max);
    memset(right_max,0,sizeof right_max);

    stack<pii>s;   // it will store the elements in increasing order

    //finding the first maximum from a position to the left

    for(int i=1;i<=n;i++){
        if(s.empty()){
            s.push({arr[i],i});
            left_max[i]=0;
        }
        else{
            int x = arr[i];
            while(s.size()>0 &&  s.top().first<=x){
                 s.pop();
            }

            if(s.empty()){
                left_max[i]=0;
            }
            else{
                left_max[i]=s.top().second;
            }
            s.push({x,i});
        }
    }

    stack<pii>s2;  // it will store the elements in increasing order
    
    
    //finding the first maximum from a position to the right

    for(int i=n;i>=1;i--){
        if(s2.empty()){
            s2.push({arr[i],i});
            right_max[i]=n+1;
        }
        else{
            int x = arr[i];
            while(s2.size()>0 &&  s2.top().first<=x){
                 s2.pop();
            }

            if(s2.empty()){
                right_max[i]=n+1;
            }
            else{
                right_max[i]=s2.top().second;
            }
            s2.push({x,i});
        }
    }
// template2 ends here
...................................








