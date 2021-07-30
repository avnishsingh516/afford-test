class Codec{
    public:
    
    virtual void recieve(int chunk, vector<byte> data) = 0;
    virtual int read(vector<byte>* data) = 0;
}

class Derived: public Codec
{
    bool marked[19] = {0};
public:
    void recieve (int chunk, vector<byte> data){
    int n=data.size();
    
    for(int i = chunk, i<chunk+n-1; i++){
        marked[i] = true;
    }
    
}

int read (vector<byte> *data){
    int i=1;
    while(marked[i]==true){
        i++;
    }
    
    return i;
}
};