#include "PmergeMe.hpp"

int check(std::string s)
{
    if(!s.length())
        return 1;
    for(int i = 0;s[i];i++)
    {
        if(!isdigit(s[i]))
            return 1;
    }
    return 0;
}

std::vector<std::pair<int,int>> merge_sort(std::vector<std::pair<int,int>> pairs)
{
    std::vector<std::pair<int,int>> right;
    std::vector<std::pair<int,int>> left;
    std::vector<std::pair<int,int>> res;

    size_t i = 0;
    for(;i < pairs.size() / 2; i++)
    {
        right.push_back(pairs[i]);
    }
    for(;i < pairs.size(); i++)
    {
        left.push_back(pairs[i]);
    }
    if(left.size() > 1)
        left = merge_sort(left);
    if(right.size() > 1)
        right = merge_sort(right);
    int x = 0;
    int y = 0;
    while(x < left.size() || y < right.size())
    {
        if(x == left.size())
        {
            res.emplace_back(right[y].first,right[y].second);
            y++;
        }
        else if(y == right.size())
        {
            res.emplace_back(left[x].first,left[x].second);
            x++;
        }
        else if(left[x].second <= right[y].second )
        {
            res.emplace_back(left[x].first,left[x].second);
            x++;
        }
        else
        {
            res.emplace_back(right[y].first,right[y].second);
            y++;
        }
    }
    return res;
}

std::vector<int> jacob_generate(int n)
{
    std::vector<int> j;
    std::vector<int> res;
    j.push_back(0);
    j.push_back(1);
    j.push_back(3);

    std :: cout << "size " <<n << std::endl;
    for(int i = 3;i < n ; i++)
    {
        j.push_back(j[i - 1] + (2 * j[i-2]));
    }
    int x = 1;
    for(int i = 0; i < j.size() ;i++)
    {
        res.push_back(j[i]);
        int y = j[i] -1;
        while(y > x)
        {
            res.push_back(y);
            y--;
        }
        x = j[i];
    }

    return res;
}


void sort_vec(std::vector<int> v)
{
    int x = -1;
    if (v.size() % 2 == 1)
    {
        x = v.back();
        v.pop_back();
    }
        // x = v[v.size() - 1];/
    std::vector<std::pair<int,int>> pairs;
    for(size_t i = 0; i + 1 < v.size(); i += 2)
    {
        if(v[i + 1] > v[i])
        pairs.emplace_back(v[i], v[i + 1]);
        else
        pairs.emplace_back(v[i + 1], v[i]);
    }
    pairs = merge_sort(pairs);

    std::vector<int> main;
    std::vector<int> pend;

    for (size_t i = 0; i < pairs.size(); i++)
    {
        if(i == 0)
        {
            main.push_back(pairs[i].first);
            main.push_back(pairs[i].second);
            continue;
        }
        main.push_back(pairs[i].second);
        pend.push_back(pairs[i].first);
    }
    // std::cout << pend.size() << std::endl;
    std::vector<int> jacob = jacob_generate(pend.size());
    for(int i = 0; i < pend.size();i++)
    {
        if (jacob[i] >= (int)pend.size())
            continue;
        std::vector<int>::iterator pos = std::lower_bound(main.begin(), main.end(), pend[jacob[i]]);
        main.insert(pos,pend[jacob[i]]);

    }
    // for(size_t i = 0; i < pend.size(); i++)
    // {
    //     std::vector<int>::iterator pos = std::lower_bound(main.begin(), main.end(), pend[i]);
    //     main.insert(pos, pend[i]);
    // }
    if(x != -1)
    {
        std::vector<int>::iterator pos = std::lower_bound(main.begin(), main.end(), x);
        main.insert(pos, x);       
    }

    for(size_t i = 0; i < main.size(); i++)
    {
        std::cout << main[i] << std::endl;    
    }
    // for(size_t i = 0; i < jacob.size(); i++)
    // {
    //     std::cout << jacob[i] << std::endl;    
    // }
}