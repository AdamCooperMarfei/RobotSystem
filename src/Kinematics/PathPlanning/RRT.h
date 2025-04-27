#include<vector>
#include<random>

namespace PathPlanning{
    class Node{
    public:
        double x_, y_;
        Node* Parent;
        std::vector<double> path_x, path_y;
        double cost;
        Node(double x, double y): x_(x), y_(y), Parent(nullptr), cost(0){};
    };
    class RRT{
    public:
        RRT(Node*, Node*, std::vector<std::vector<double>>, std::vector<double>, 
            double, double, double, double);
        std::vector<Node*> planning();
        Node* GetNearestNode(const std::vector<double>);
        bool CollisionCheck(Node*);
    protected:
        Node* steer(Node*, Node*, float extend_length);
        Node* start, end;
        const double expand_dis, path_resolution;
        const int goal_sample_rate, max_iter;
        const std::vector<std::vector<double>> ob_list;
        std::vector<double> rand_area;
        std::vector<Node*> node_list;
        //随机种子
        std::random_device goal_rd, area_rd;
        std::mt19937 goal_gen, area_gen;
        std::uniform_int_distribution<int> goal_dis, area_dis;
        static std::vector<double> calc_distance_and_angle(Node*, Node*);
        
    };
    

}