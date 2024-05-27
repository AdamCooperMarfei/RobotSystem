#include<vector>
namespace singleaxisspeedplan{
    class SingleAxisSpeedPlan{
    public:
        SingleAxisSpeedPlan(double cur_pos): m_cur_pos(cur_pos){}
        virtual ~SingleAxisSpeedPlan(){}
        virtual void MoveTo(double target_pos) = 0;
    private:
        double m_cur_pos, m_target_pos;
        std::vector<double> m_s_list;

    };
}

