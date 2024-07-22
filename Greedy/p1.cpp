class Solution
{
    public:
    
    class Meet{
        public:
            int start;
            int end;
            int pos;
    };
    
    static bool comparator(Meet m1, Meet m2){
        // First sort n=on basis of endTime , if matches then on basis of position.
        if(m1.end<m2.end) return true;
        else if(m1.end>m2.end) return false;
        else if(m1.pos<m2.pos) return true;
        return false;
    }
    
    int maxMeetings(int start[], int end[], int n)
    {
        // Approach
        
        // create array of meeting.
        Meet meet[n];
        for(int i=0; i<n; i++){
            meet[i].start = start[i];
            meet[i].end = end[i];
            meet[i].pos = i+1;
        }
        
        // sort the meeting according to end time
        sort(meet, meet + n ,comparator);
        
        int count=1;
        int freeTime = meet[0].end;
        for(int i=1; i<n; i++){
            int startTime = meet[i].start;
            if(startTime>freeTime){
                count++;
                freeTime = meet[i].end;
            }
        }
        
        return count;
        
    }
};

// TC : O(N) + O(NlogN) + O(N)
// SC : O(3N) + O(N)