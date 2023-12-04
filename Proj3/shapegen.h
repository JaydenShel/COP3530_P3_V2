#ifndef SHAPEGEN_H
#define SHAPEGEN_H

#include <algorithm>
#include <cfloat>
#endif // SHAPEGEN_H
#pragma once
#include <vector>
#include <unordered_set>
#include <math.h>


class ShapeGenerator{
    struct Point{
        float x;
        float y;
        float cosAng;
        Point(float x_in, float y_in){
            x = x_in;
            y = y_in;
        }
        Point(){}
        bool operator==(const Point& rhs) const{
            return (this->x == rhs.x && this->y == rhs.y);
        }
        bool operator<(const Point& rhs) const{
            return (this->x < rhs.x);
        }
        struct HashFunction{
            size_t operator()(const Point& p)const{
                return std::hash<float>()(p.x*p.y+p.y);
            }
        };
    };
    struct Edge{
        Point* A;
        Point* B;
        Edge(Point A_in, Point B_in){
            A = &A_in;
            B = &B_in;
        }
        Edge(){}
        bool operator==(const Edge& rhs) const{
            return ((rhs.A == A && rhs.B == B) || (rhs.A == B && rhs.B == A));
        }
    };
    struct Circle{
        float x,y,r;
        Circle(){}
    };
    struct Triangle{
        Point* A;
        Point* B;
        Point* C;
        Edge* AB;
        Edge* BC;
        Edge* AC;
        Circle circ;
        Triangle(Point A_in, Point B_in, Point C_in){
            A = &A_in;
            B = &B_in;
            C = &C_in;


            const float Dx = B->x - A->x;
            const float Dy = B->y - A->y;
            const float Ex = C->x - A->x;
            const float Ey = C->y - A->y;

            const float M = B->x * B->x - A->x * A->x + B->y * B->y - A->y * A->y;
            const float U = C->x * C->x - A->x * A->x + C->y * C->y - A->y * A->y;
            const float S = 1./(2.*(Dx*Ey - Dy*Ex));

            circ.x = ((C->y - A->y) * M + (A->y-B->y) * U) * S;
            circ.y = ((A->x - C->x) * M + (B->x - A->x) * U) * S;

            const float dx = A->x - circ.x;
            const float dy = A->y - circ.y;
            circ.r = dx*dx + dy*dy;
        }
    };
    struct Delaunay{
        std::vector<Triangle> triangles;
        std::vector<Edge> edges;
    };
    Delaunay triangulate(const std::vector<Point> &points){
        if(points.size() <3) return Delaunay();

        float xmin = points[0].x;
        float xmax = xmin;
        float ymin = points[0].y;
        float ymax = ymin;

        for(Point pt : points){
            xmin = std::min(xmin,pt.x);
            xmax = std::max(xmax,pt.x);
            ymin = std::min(ymin,pt.y);
            ymax = std::max(ymax,pt.y);
        }

        const float dx = xmax - xmin;
        const float dy = ymax - ymin;
        float dmax = std::max(dx,dy);
        float midx = (xmin+xmax)/2.0;
        float midy = (ymin+ymax)/2.0;

        Delaunay d;

        Point A(midx-20*dmax,midy-dmax);
        Point B(midx,midy +20*dmax);
        Point C(midx+20*dmax, midy-dmax);
        d.triangles.emplace_back(Triangle(A,B,C));

        for(Point pt:points){
            std::vector<Edge> edges;
            std::vector<Triangle> temps;
            for(Triangle t : d.triangles){
                const float dist = (t.circ.x - pt.x) * (t.circ.x - pt.x) + (t.circ.y - pt.y) * (t.circ.y - pt.y);
                if((dist-t.circ.r) <= 0.0004){
                    edges.push_back(Edge(*t.A,*t.B));
                    edges.push_back(Edge(*t.B,*t.C));
                    edges.push_back(Edge(*t.A,*t.C));
                }else{
                    temps.push_back(t);
                }
            }

            std::vector<bool> remove(edges.size(),false);
            for(auto it1 = edges.begin();it1 != edges.end();it1++){
                for(auto it2 = edges.begin();it2 != edges.end();it2++){
                    if(it1==it2) continue;
                    if(*it1 == *it2){
                        //remove[std::distance(edges.begin(), it1)];
                        //remove[std::distance(edges.begin(), it2)];
                    }
                }
            }

            edges.erase(
                std::remove_if(edges.begin(),edges.end(),
                               [&](auto const& e){return remove[&e - &edges[0]];}),
                edges.end());
            for(auto const& e:edges){
                temps.push_back(Triangle(*e.A,*e.B,Point(pt.x,pt.y)));
            }
            d.triangles = temps;
        }

        d.triangles.erase(
            std::remove_if(d.triangles.begin(), d.triangles.end(),
                           [&](auto const& tri) {
                               return ((*tri.A == A || *tri.B == A || *tri.C == A) ||
                                       (*tri.A == B || *tri.B == B || *tri.C == B) ||
                                       (*tri.A == C || *tri.B == C || *tri.C == C));
                           }),
            d.triangles.end());
        for (auto const& tri : d.triangles) {
            d.edges.push_back(Edge(*tri.A,*tri.B));
            d.edges.push_back(Edge(*tri.B,*tri.C));
            d.edges.push_back(Edge(*tri.A,*tri.C));
        }
        return d;
    }

private:
    std::unordered_set<Point,Point::HashFunction> points;
    std::vector<Edge> edges;
    float FindCos(Point p0, Point p1){
        float xLeg = p1.x - p0.x;
        float yLeg = p1.y - p0.y;
        float hyp = sqrt(pow(xLeg,2)+pow(yLeg,2));
        return xLeg/hyp;
    }
    int findSide(Point p1, Point p2, Point p){
        int val = (p.y - p1.y) * (p2.x - p1.x) -(p2.y - p1.y) * (p.x - p1.x);

        if (val > 0)
            return 1;
        if (val < 0)
            return -1;
        return 0;
    }
    int lineDist(Point p1, Point p2, Point p)
    {
        return abs ((p.y - p1.y) * (p2.x - p1.x) -(p2.y - p1.y) * (p.x - p1.x));
    }
    void quickHull(std::vector<Point> a, std::vector<Point> &hull, int n, Point p1, Point p2, int side)
    {
        int ind = -1;
        int max_dist = 0;

        // finding the point with maximum distance
        // from L and also on the specified side of L.
        for (int i=0; i<n; i++)
        {
            int temp = lineDist(p1, p2, a[i]);
            if (findSide(p1, p2, a[i]) == side && temp > max_dist)
            {
                ind = i;
                max_dist = temp;
            }
        }

        // If no point is found, add the end points
        // of L to the convex hull.
        if (ind == -1)
        {
            hull.push_back(p1);
            hull.push_back(p2);
            return;
        }

        // Recur for the two parts divided by a[ind]
        quickHull(a,hull, n, a[ind], p1, -findSide(a[ind], p1, p2));
        quickHull(a,hull, n, a[ind], p2, -findSide(a[ind], p2, p1));
    }
public:
    ShapeGenerator(){}
    std::vector<std::pair<float,float>> ConvexHull(std::vector<std::pair<float,float>> &vals){
        int init_p0 = 0;
        int heap_beg = -1;
        Point* P0;
        for(int i=0;i<vals.size();i++){
            Point p(vals[i].second,vals[i].first);
            points.insert(p);

            if(vals[init_p0].first == vals[i].first){
                if(vals[i].second < vals[init_p0].second){
                    init_p0 = i;
                    P0 = &p;
                }
            }else if(vals[init_p0].first > vals[i].first){
                init_p0 = i;
                P0 = &p;
            }
        }
        std::vector<std::pair<float, Point>> pointHeap;

        for(auto it = points.begin();it != points.end();++it){
            if(*P0 == *it) continue;
            float curCos = FindCos(*P0,*it);
            std::pair<float, Point> child(curCos,*it);
            pointHeap.push_back(child);
        }
        std::sort(pointHeap.begin(),pointHeap.end());
        std::reverse(pointHeap.begin(),pointHeap.end());
        std::vector<Point> pointStack;
        pointStack.push_back(*P0);
        for(int i=0;i<pointHeap.size();i++){
            if(i==0){
                pointStack.push_back(pointHeap[0].second);
            }else{
                pointStack.push_back(pointHeap[i].second);
                Point* p1 = &pointStack[i-1];
                Point* p2 = &pointStack[i];
                Point* p3 = &pointStack[i+1];
                float sign = (p2->x - p1->x)*(p3->y-p1->y)-(p2->y-p1->y)*(p3->x-p1->x);

                if(sign<0){

                    pointStack.erase(pointStack.begin()+i-1,pointStack.begin()+i);
                }
            }
        }
        std::vector<std::pair<float,float>> result;
        for(auto p:pointStack){
            result.push_back(std::pair<float,float>(p.x,p.y));
        }
        return result;
    }
    std::vector<std::pair<std::pair<float,float>>> AlphaShape(std::vector<std::pair<float,float>> &vals){

        std::sort(vals.begin(),vals.end());
        for(int i=0;i<vals.size();i++){
            Point p(vals[i].second,vals[i].first);
            points.insert(p);
        }
        std::vector<Point> sortedVals;

        for(auto it = points.begin();it != points.end();++it){
            sortedVals.push_back(*it));
        }
        Delaunay d;
        d = triangulate(sortedVals);

        std::vector<std::pair<std::pair<float,float>>>> result;

        return d.edges;

    }
    std::vector<std::pair<float,float>> QuickHull(std::vector<std::pair<float,float>> &vals){
        points.clear();
        std::vector<std::pair<float,float>> result;
        std::vector<Point> setPoints;
        for(int i=0;i<vals.size();i++){
            Point p(vals[i].second,vals[i].first);
            if(points.insert(p).second){
                setPoints.push_back(p);
            };
        }
        int min_x = 0, max_x = 0;
        for (int i=1; i<setPoints.size(); i++){
            if (setPoints[i].x < setPoints[min_x].x)
                min_x = i;
            if (setPoints[i].x > setPoints[max_x].x)
                max_x = i;
        }
        std::vector<Point> hull;
        quickHull(setPoints,hull,setPoints.size(), setPoints[min_x],setPoints[max_x],1);

        for(auto p:hull){
            result.push_back(std::pair<float,float>(p.x,p.y));
        }
        return result;
    }
};

