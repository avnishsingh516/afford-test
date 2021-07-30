class Codec{
    public:
    
    virtual compressedData compress(string decompressedData) = 0;
    virtual decompressedData decompress(string compressedData) = 0
}

class Derived: public Codec
{
public:
    string compress(string decompressedData){
        string compressData = "";
    
    for(int i=0; i<decompressedData.size(); i++){
        int count = 1;
        while(decompressedData[i]==decompressedData[i+1] and i<decompressedData.size()-1){
            count++;
            i++;
        }
        
        compressData += decompressedData[i];
        if(count > 1){
        compressData += (count + '0');
        }
    }
    
    compressData += '\0';
    // cout<<compressData;
    return compressData;
    }
    
    string decompress(string compressedData){
        string decompressData="";
    
    for(int i=0; i<compressedData.size(); i++){
        if(compressedData[i]>='1' and compressedData[i]<='9'){
            int count = compressedData[i]-'0';
            
            while(count>1){
                decompressData += compressedData[i-1];
                count--;
            }
            i++;
        }
        decompressData += compressedData[i];
    }
    
    decompressData += '\0';
    return decompressData;
    }
};