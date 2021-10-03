class MedianFinder {
public:
    /** initialize your data structure here. */
    
    priority_queue<int> pq_max;
    priority_queue<int,vector<int>, greater<int> > pq_min;
    
    
    MedianFinder() {
        //nlogn 
    }
    
    void addNum(int nums) 
    {
        if( pq_max.size() == 0 ||  pq_max.top() > nums) pq_max.push(nums) ;
        else 
            pq_min.push(nums) ;
       
         if( pq_max.size() > pq_min.size()+ 1 )
        {
            
                //diff of size should not be greater than 1 and pq_max.size() > pq_min.size() so before adding we pop the pq_max.top and push it in pq_min
                pq_min.push( pq_max.top() ) ;
                pq_max.pop() ;
        }
        if( pq_min.size() > pq_max.size() + 1 )
        {
          
                pq_max.push( pq_min.top() ) ;
                pq_min.pop() ;
          
        }
        
    }
    
    double findMedian() 
    {
        if( pq_min.size() == pq_max.size() ) 
        {
            return pq_max.empty() ? 0 : (pq_max.top() + pq_min.top())/2.0 ; 
        }
        else 
        {
            if( pq_max.size() > pq_min.size() ) return pq_max.top() ;
            else 
                return pq_min.top() ;
        }
        return 0.0;
    }
};
