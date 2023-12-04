#ifndef SHAPEGEN_H
#define SHAPEGEN_H

#include <algorithm>
#include <cfloat>
#endif // SHAPEGEN_H
#pragma once
#include <vector>
#include <unordered_set>
#include <math.h>
using namespace std;

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
        struct HashFunction{
            size_t operator()(const Point& p)const{
                return hash<float>()(p.x*p.y+p.y);
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
                        remove[std::distance(edges.begin(), it1)];
                        remove[std::distance(edges.begin(), it2)];
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
                       return ((tri.A == A || tri.B == A || tri.C == A) ||
                               (tri.A == B || tri.B == B || tri.C == B) ||
                               (tri.A == C || tri.B == C || tri.C == C));
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
    unordered_set<Point,Point::HashFunction> points;
    vector<Edge> edges;
    float FindCos(Point p0, Point p1){
        float xLeg = p1.x - p0.x;
        float yLeg = p1.y - p0.y;
        float hyp = sqrt(pow(xLeg,2)+pow(yLeg,2));
        return xLeg/hyp;
    }
public:
    ShapeGenerator(){}
    vector<Point> ConvexHull(vector<pair<float,float>> vals){
        int init_p0 = 0;
        Point* P0;
        for(int i=0;i<vals.size();i++){
            Point p(vals[i].first,vals[i].second);
            points.insert(p);

            if(vals[init_p0].second == vals[i].second){
                if(vals[i].first < vals[init_p0].first){
                    init_p0 = i;
                    P0 = &p;
                }
            }else if(vals[init_p0].second > vals[i].second){
                init_p0 = i;
                P0 = &p;
            }
        }

        vector<pair<Point, float>> pointHeap(points.size());
        int heap_end = 0;
        for(auto it = points.begin();it!=points.end();it++){
            if(*P0 == *it) continue;
            float curCos = FindCos(*P0,*it);
            pair<Point, float> child(*it, curCos);

            pointHeap[heap_end] = child;
            if(heap_end ==0) continue;
            int parentPos = (heap_end-1)/2;
            int childPos = heap_end;
            while(parentPos>=0 && pointHeap[parentPos].second < pointHeap[childPos].second){
                pair<Point, float> temp(child);
                pointHeap[childPos] = pointHeap[parentPos];
                pointHeap[parentPos] =  temp;
                childPos = parentPos;
                parentPos = (childPos-1)/2;
            }
            heap_end++;
        }
        vector<Point> pointStack;
        pointStack.push_back(*P0);
        for(int i=0;i<pointHeap.size();i++){
            if(i==0){
                pointStack.push_back(pointHeap[0].first);
            }else{
                pointStack.push_back(pointHeap[0].first);
                Point* p1 = &pointStack[i-1];
                Point* p2 = &pointStack[i];
                Point* p3 = &pointStack[i+1];
                float sign = (p2->x - p1->x)*(p3->y-p1->y)-(p2->y-p1->y)*(p3->x-p1->x);
                if(sign<0){
                    pointStack.erase(pointStack.begin()+i-1);
                }
            }

            pointHeap[0] = pointHeap[--heap_end];
            pointHeap[heap_end].second = -FLT_MAX;
            int index = 0;
            while(index*2+1 <heap_end && pointHeap[index].second > min(pointHeap[index*2+1].second,pointHeap[index*2+2].second)){
                if(pointHeap[index*2+1].second >pointHeap[index*2+2].second){
                    pair<Point, float> temp(pointHeap[index]);
                    pointHeap[index] = pointHeap[index*2+1];
                    pointHeap[index*2+1] = temp;
                    index = index*2+1;
                }else{
                    pair<Point, float> temp(pointHeap[index]);
                    pointHeap[index] = pointHeap[index*2+2];
                    pointHeap[index*2+2] = temp;
                    index = index*2+2;
                }
            }
        }
        return pointStack;
    }
    vector<Point> AlphaShape(vector<pair<float,float>> vals){

        for(int i=0;i<vals.size();i++){
            Point p(vals[i].first,vals[i].second);
            points.insert(p);
        }

        vector<pair<Point, float>> pointHeap(points.size());
        int heap_end = 0;
        for(auto it = points.begin();it!=points.end();it++){
            pair<Point, float> child(*it, it->x);

            pointHeap[heap_end] = child;
            if(heap_end ==0) continue;
            int parentPos = (heap_end-1)/2;
            int childPos = heap_end;
            while(parentPos>=0 && pointHeap[parentPos].second > pointHeap[childPos].second){
                pair<Point, float> temp(child);
                pointHeap[childPos] = pointHeap[parentPos];
                pointHeap[parentPos] =  temp;
                childPos = parentPos;
                parentPos = (childPos-1)/2;
            }
            heap_end++;
        }
        vector<Point> pointStack;
        for(int i=0;i<pointHeap.size();i++){
            if(i==0){
                pointStack.push_back(pointHeap[0].first);
            }else{
                pointStack.push_back(pointHeap[0].first);
                Point* p1 = &pointStack[i-1];
                Point* p2 = &pointStack[i];
                Point* p3 = &pointStack[i+1];
                float sign = (p2->x - p1->x)*(p3->y-p1->y)-(p2->y-p1->y)*(p3->x-p1->x);
                if(sign<0){
                    pointStack.erase(pointStack.begin()+i-1);
                }
            }

            pointHeap[0] = pointHeap[--heap_end];
            pointHeap[heap_end].second = -FLT_MAX;
            int index = 0;
            while(index*2+1 <heap_end && pointHeap[index].second < min(pointHeap[index*2+1].second,pointHeap[index*2+2].second)){
                if(pointHeap[index*2+1].second <pointHeap[index*2+2].second){
                    pair<Point, float> temp(pointHeap[index]);
                    pointHeap[index] = pointHeap[index*2+1];
                    pointHeap[index*2+1] = temp;
                    index = index*2+1;
                }else{
                    pair<Point, float> temp(pointHeap[index]);
                    pointHeap[index] = pointHeap[index*2+2];
                    pointHeap[index*2+2] = temp;
                    index = index*2+2;
                }
            }
        }

    }

};

