       pass[i]=(pass[i] + 2)%127;
            cout<<pass[i];
        }
        cout<<endl;
           for(int i=0;i<pass.size();i++){
            pass[i]=(pass[i] - 2)%127;