class LFUCache 
{
    int cap;
    int size;
    int minFreq;
    unordered_map<int, pair<int, int>> keyValFreq; //key to {value,freq};
    unordered_map<int, list<int>::iterator> keyIter; //key to list iterator;
    unordered_map<int, list<int>> freqKeys;  //freq to key list;
public:
    LFUCache(int capacity) 
    {
        cap=capacity;
        size=0;
    }
    
    int get(int key) 
    {
        if(keyValFreq.count(key) == 0) 
            return -1;

        freqKeys[keyValFreq[key].second].erase(keyIter[key]);
        keyValFreq[key].second++;
        freqKeys[keyValFreq[key].second].push_back(key);
        keyIter[key]= --freqKeys[keyValFreq[key].second].end();
        
        if(freqKeys[minFreq].size() == 0) 
            minFreq++;
        
        return keyValFreq[key].first;
    }
    
    void put(int key, int value) 
    {
        if(cap <= 0) 
            return;
        
        int storedValue = get(key);
        if(storedValue != -1)
        {
            keyValFreq[key].first = value;
            return;
        }
        
        if(size >= cap) 
        {
            keyValFreq.erase(freqKeys[minFreq].front());
            keyIter.erase(freqKeys[minFreq].front());
            freqKeys[minFreq].pop_front();
            size--;
        }
        
        keyValFreq[key] = {value, 1};
        freqKeys[1].push_back(key);
        keyIter[key]= --freqKeys[1].end();
        minFreq = 1;
        size++;
    }
};