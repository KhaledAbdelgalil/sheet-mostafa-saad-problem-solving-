#include<bits/stdc++.h>
using namespace std;
#define all(v)  ((v).begin()), ((v).end())
vector< pair<pair <int,int>, set<int> > > fs;
vector< pair< int, set<int> > > vf;
vector< pair <int,int> > output_slides;//pair of first photo id and 2nd photo id if 2nd photo==-1 so print 1st only as it's horizontal
map<string, int> ids;
/* variables will be used to solve problem*/
char H_or_V;// to check if it's horizontal or vertical photo
int tags_number;// represent number of tags in a photo
int n;//n represents number of photos

//prototypes of functions used to solve problem
void print_output();
int calc(const set<int> &a, const set<int> &b);
void getting_input_forming_horizontalSlides_and_verticalPhotos(int n);


int main()
{
  cin >> n;// take number of photos

  /* taking inputs and forming slides*/
  getting_input_forming_horizontalSlides_and_verticalPhotos(n);

  for(int i=0;i<vf.size();i++)
    {
        if (vf[i].first == -1)
            continue;
        int best = -1, id;
        for(int j=i + 1;j<(int)vf.size();j++)
        {
            if (vf[j].first == -1) continue;
            int tmp = 0;
            std::set<int>::iterator it;
            for (it = vf[j].second.begin(); it != vf[j].second.end(); ++it)
                if (!vf[i].second.count(*it))++ tmp;
            if (tmp > best)
                {
                    best = tmp;
                    id = j;
                }
        }
        if (best == -1) continue;
        vf[i].second.insert(all(vf[id].second));//add tags of 2nd vertical photos to 1st vertical photo to form tags of full slide
        fs.push_back(make_pair(make_pair(vf[i].first, vf[id].first), vf[i].second));//here slide consists of  2 vertical photos
        vf[id].first = -1;
    }

  set<int> prev;
  int sum = 0;
  for(int x=0;x<int(fs.size());x++)
    {
        int best = -1, id;
        for(int i=0;i<int(fs.size());i++)
        {
            if (fs[i].first.first == -1) continue;
            int tmp = calc(prev, fs[i].second);
            if (tmp > best)
            {
                best = tmp;
                id = i;
            }
        }
        output_slides.push_back(fs[id].first);
        fs[id].first.first = -1;
        prev = fs[id].second;
        sum += best;
    }
  print_output();
  return 0;
}

//implementations of functions used to solve problem

/*function used to iterate over output vector and print ids of photos used to form slides*/
void print_output()
{
    cout << int(output_slides.size()) << endl;
   for(int i=0;i<int(output_slides.size());i++)
   {
        cout << output_slides[i].first;
        if (output_slides[i].second != -1)//if it's 2 vertical photos-slide
            cout << " " << output_slides[i].second;
        cout << endl;
    }
}
/*function used to return minmum interest*/
int calc(const set<int> &a, const set<int> &b)
{
  int comm = 0;
  std::set<int>::iterator it;
    for (it = a.begin(); it != a.end(); ++it)
    {
        if (b.count(*it))++ comm;
    }

  int aa =a.size() - comm;
  int bb = b.size() - comm;
  return min(comm, min(aa, bb));
}
/*function used to take input and forming horizantal slides and vertical photos*/
void getting_input_forming_horizontalSlides_and_verticalPhotos(int n)
{
  for(int i=0;i<n;i++)
    {
        cin >> H_or_V >> tags_number;
        set<int> v;
        while (tags_number--)
        {
            string tag;
            cin >> tag;//taking tag
            if (ids.count(tag)) v.insert(ids[tag]);
            else {
                    int id = (int)ids.size();
                    v.insert(id);
                    ids[tag] = id;
                 }
        }
        if (H_or_V == 'H') fs.push_back(make_pair(make_pair(i, -1), v));//-1 becauese the slide have only one horizontal photo //i represents photo_id
        else          vf.push_back(make_pair(i, v));
    }
}
