/*
Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
*/

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
 
class Solution {
public:

    int maxPoints(vector<Point> &points) {
        
        if(points.size()<=2)
            return points.size();
            
        int maxPoints = 2;
        
        for(int i = 0; i < points.size()-1; ++i){
            
            Point& src = points[i];
            //slope <-> points except src
            unordered_map<double, int> cache;
            cache.clear();
            //number of points same as src
            int duplicates = 1;
            
            for(int j = i + 1 ; j < points.size(); ++j){
                
                Point& dest = points[j];
                
                if(dest.x==src.x&&dest.y==src.y){
                    ++duplicates;
                    continue;
                }
                
                double slope = 0.0;
                if(src.x==dest.x)
                    slope = (double)INT_MAX;
                else
                    slope = (double)(dest.y-src.y)/(double)(dest.x-src.x);
                
                if(cache.count(slope)==0)
                    cache[slope]=1;
                else
                    cache[slope]++;
            }
            
            //update local max
            int count = 0;
            unordered_map<double,int >::iterator iter = cache.begin();
            while(iter != cache.end()){
                count = max(iter->second,count);
                ++iter;
            }
            
            //update global max
            maxPoints = max(maxPoints, count+duplicates );
        }
 
        return maxPoints;
    }
    
};