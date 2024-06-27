#include <string>
#include <vector>
#include <string>
#include <iostream>
#include <map>

using namespace std;

//��Ǭ�ڵ��Ӥ��������� ���� ����...
//������ - ���̾��� �� ȭ�� �迭 ����Ʈ
map<int, vector<vector<int>>> lion_info_list;

//���� ���� ���� ������ 
int max_score_gap = -1;

void print_lion_info(vector<int>& lion_info) {
    for (int a : lion_info) {
        cout << a << ' ';
    }
    cout << "\n\n";
}

//10��~0���� �� �� ���� �� Ƚ�� ���ϱ�
void set_min_arrow(int now_idx, int last_arrow, int peach_total, vector<int>& peach_info, int lion_sum, vector<int>& lion_info) {



    if (now_idx == 11) {
        //ȭ���� �� �����.


        if (peach_total < lion_sum) {
            //���̾��� ���
            int score_gap = lion_sum - peach_total;

            if (max_score_gap < score_gap) {
                lion_info_list[score_gap].push_back(lion_info);
                max_score_gap = score_gap;

                if (lion_info[0] == 0) {
                    cout << "lion_sum : " << lion_sum << "peach_score : " << peach_total << '\n';
                    print_lion_info(lion_info);
                }
            }
        }

        return;
    }

    //������ ȭ���̸� �ڵ����� ���� ȭ�� ����
    if (now_idx == 10) {
        int arrow = last_arrow;
        int get_score = 0;
        int peach_score = 0;
        if (peach_info[now_idx] < arrow && arrow != 0) {
            get_score = 10 - now_idx;

        }
        else {
            if (arrow != 0) {
                peach_score = 10 - now_idx;
            }
        }

        //���� ���� ȭ�� ������
        lion_info[now_idx] = arrow;
        set_min_arrow(now_idx + 1, last_arrow - arrow, peach_total + peach_score, peach_info, lion_sum + get_score, lion_info);
        lion_info[now_idx] = 0;

    }
    else {
        //���� ȭ�� ���ϱ� 
        for (int arrow = 0; arrow <= last_arrow; arrow++) {
            int get_score = 0;
            int peach_score = 0;

            if (peach_info[now_idx] < arrow && arrow != 0) {
                get_score = 10 - now_idx;
            }
            else {
                if (arrow != 0) {
                    peach_score = 10 - now_idx;
                }
            }

            //cout << get_score << '\n';
            //���� ���� ȭ�� ������
            lion_info[now_idx] = arrow;
            set_min_arrow(now_idx + 1, last_arrow - arrow, peach_total + peach_score, peach_info, lion_sum + get_score, lion_info);
            lion_info[now_idx] = 0;

        }
    }





}


vector<int> solution(int n, vector<int> info) {
    vector<int> answer;
    vector<int> lion_info(11);
    //ȭ���� 110���� total
    int peach_total = 0;

    set_min_arrow(0, n, peach_total, info, 0, lion_info);

    if (max_score_gap == -1) answer.push_back(-1);
    else {
        int min_idx = 10;
        int min_num = 200;
        int idx = 0;
        cout << max_score_gap << ' ' << peach_total;
        for (vector<int> v : lion_info_list[max_score_gap]) {

            if (idx == 0) {
                for (int i = 10; i >= 0; i--) {
                    if (v[i] > 0) {
                        min_num = v[i];
                        min_idx = i;
                        answer = v;
                    }
                }
            }
            else {
                for (int i = 10; i >= 0; i--) {
                    if (min_idx < i && v[i] > 0) {
                        min_idx = i;
                        min_num = v[i];
                        answer = v;
                    }
                    else if (min_idx == i && v[i] > 0 && min_num < v[i]) {
                        min_idx = i;
                        min_num = v[i];
                        answer = v;
                    }

                }
            }
        }
    }

    return answer;
}


int main(int argc, char** argv) {
    int n = 5;
    vector<int> info{ 2, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0};
    vector<int> answer = solution(n, info);

    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << ' ';
    }
}