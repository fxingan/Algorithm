#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;

struct People_Type {
    string name;
    string pair_name;
    string preference[1001];
    map<string, int> order_of_preference;
    bool is_matched = 0;
};
struct Information_of_People_Type {
    int index;
};
// 字符串解析函数
void Analysis_Temp_Message(vector<People_Type>& people, string temp_message, map<string, int>& detail, int index);

// 最适匹配函数
void Match_Function(vector<People_Type>& men, vector<People_Type>& women,
    map<string, int>& detail_index_men, map<string, int>& detail_index_women, int n);

// 结果输出
void Print_Out(vector<People_Type>& men, int n);

int main() {
    vector<People_Type> Men(1001);
    vector<People_Type> Women(1001);
    map<string, int> Detali_index_Men;
    map<string, int> Detali_index_Women;
    string Temp_Message;
    // 输入总配对数：n 对
    int N;
    cin >> N;
    // 输入男性，即A，B，C……
    for (int index = 0; index < N; index++) {
        cin >> Temp_Message;
        Analysis_Temp_Message(Men, Temp_Message, Detali_index_Men, index);
    }
    // 输入女性，即x，y，z……
    for (int index = 0; index < N; index++) {
        cin >> Temp_Message;
        Analysis_Temp_Message(Women, Temp_Message, Detali_index_Women, index);
    }

    // 匹配
    Match_Function(Men, Women, Detali_index_Men, Detali_index_Women, N);

    // 输出
    Print_Out(Men, N);

    return 0;

}

/*
* 最适匹配函数
*/
void Match_Function(vector<People_Type>& men, vector<People_Type>& women,
    map<string, int>& detail_index_men, map<string, int>& detail_index_women, int n) {
    int i = 0, j = 0;
    while (1) {
        int the_women_index = detail_index_women[men[i].preference[j]];

        if (i >= n) {
            break;
        }
        if (men[i].is_matched == 1) {
            i++;
            continue;
        }

        if (men[i].is_matched == 0 && women[the_women_index].is_matched == 0) {
            men[i].is_matched = 1;
            women[the_women_index].is_matched = 1;
            men[i].pair_name = men[i].preference[j];
            women[the_women_index].pair_name = men[i].name;
            // 下一个男性开始匹配
            i++;
            j = 0;
        }
        else if (men[i].is_matched == 0 && women[detail_index_women[men[i].preference[j]]].is_matched == 1) {
            // 先比较女性更喜欢哪一个男性
            if (women[the_women_index].order_of_preference[men[i].name] >
                women[the_women_index].order_of_preference[women[the_women_index].pair_name]) {
                // 如果女性更喜欢之前匹配到的男性，则此男性与下一位女性尝试匹配
                j++;
            }
            else {
                /*
                * 如果女性更喜欢现在匹配到的男性
                * 1.取消与之前男性的配对关系，
                * 2.并且与现在的男性建立新的配对关系
                * 3.最后男性指针指向此女性之前配对的男性
                */
                // step.1
                string pre_men_name = women[detail_index_women[men[i].preference[j]]].pair_name;
                int pre_men_index = detail_index_men[pre_men_name];
                men[pre_men_index].is_matched = 0;
                men[pre_men_index].pair_name.clear();
                // step.2
                men[i].is_matched = 1;
                women[the_women_index].is_matched = 1;
                men[i].pair_name = women[the_women_index].name;
                women[the_women_index].pair_name = men[i].name;
                // step.3
                i = pre_men_index;
                j = 0;
            }
        }
    }
}

/*
* 字符串解析
* 1.给每个人建立结构体
* 2.有序记录每个人喜欢的异性，并且量化喜欢程度
*/
void Analysis_Temp_Message(vector<People_Type>& people, string temp_message, map<string, int>& detail, int index) {
    // 提取姓名
    int i = 0;
    while (temp_message.at(i) != ':') {
        people[index].name += temp_message.at(i);
        i++;
    }
    // 越过冒号到下一个字符
    i++;
    // 提取对应perference程度,并且用map-order_of_preference量化喜欢程度
    int j = 0;
    string temp_preference_name;
    while (i < temp_message.length()) {
        if (temp_message.at(i) != '>') {
            temp_preference_name += temp_message.at(i);
            i++;
        }
        else {
            people[index].preference[j] = temp_preference_name;
            people[index].order_of_preference.insert(map<string, int>::value_type(temp_preference_name, j));
            temp_preference_name.clear();
            i++;
            j++;
        }
    }
    people[index].preference[j] = temp_preference_name;
    people[index].order_of_preference.insert(map<string, int>::value_type(temp_preference_name, j));
    // 利用map存储对应名字的索引值
    detail.insert(map<string, int>::value_type(people[index].name, index));

}


/*
* 结果输出
*/
void Print_Out(vector<People_Type>& men, int n) {
    for (int i = 0; i < n; i++) {
        cout << '(' << men[i].name << ',' << men[i].pair_name << ')' << endl;
    }
}
