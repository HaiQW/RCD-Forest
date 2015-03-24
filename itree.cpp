#include"itree.h"
/****************************************
*itree's construct function with parameter
****************************************/
iTree::iTree(DataProcess* data_procession,int height_max)
{
         data_procession_ = data_procession;
         height_max_ = height_max;
        //new root节点
         itree_root_ = new t_INode();
         itree_root_->parent_node_ = NULL;
         itree_root_->left_node_ = NULL;
         itree_root_->right_node_ = NULL;
}

/****************************************
*ITree带参数的析构函数
/***************************************/
iTree::~iTree()
{

}

/****************************************
*构建一颗iTree
****************************************/
void iTree::BuildITree()
{
  //get normalized data set from data_procession_
  std::vector<t_Data> data_set =
      data_procession_->GetNormalizedDataSet();
  //buildTree
  BuildITree(&data_set,itree_root_,0);
}

/****************************************
*构建一颗iTree
*current_height：当前树的高度
****************************************/
void iTree::BuildITree(std::vector<t_Data>* data_set,
                       t_INode* root ,
                       int current_height)
{
  std::vector<t_Data> left_data_set ;
  std::vector<t_Data> right_data_set ;
  double split_point = DBL_MIN;
  int dimension_index = INT_MIN;
  bool split_flag = false;

  //将数据集合分割成左右两个部分
  int count = 0;
  while(split_flag == false && count < 10)
    {
      count++;
      split_flag = data_procession_->DeterministicSplitDataSet(&left_data_set,
                                                           &right_data_set,
                                                           dimension_index,
                                                           split_point,
                                                           data_set);
    }

  //是否判断是否可以继续分割
  if( split_flag == false || current_height >= height_max_)
  {
    root->left_node_ = NULL;
    root->right_node_ = NULL;
    root->node_size_ = data_set->size();
    root->variance_ =data_procession_->CalculateVariance(data_set);
    //std::cout<<"OK"<<std::endl;
    return ;
  }
  else
  {
    t_INode* left_node = new t_INode();
    t_INode* right_node = new t_INode();
    left_node->parent_node_ = root;
    right_node->parent_node_ = root;
    root->variance_ = data_procession_->CalculateVariance(data_set);
    root->dimension_index_ = dimension_index;
    root->node_size_= data_set->size();
    root->split_value_ = split_point;
    root->left_node_ = left_node;
    root->right_node_ = right_node;
    BuildITree(&left_data_set,left_node,current_height+1);
    BuildITree(&right_data_set,right_node,current_height+1);
    return ;
  }
}

/****************************************
*返回itree 的根节点
****************************************/
t_INode* iTree::GetRoot()
{
  return itree_root_;
}

/****************************************
*print the itree without parameter
****************************************/
void iTree::PrintITree()
{
  PrintITree(itree_root_);
}

/****************************************
*print the itree
****************************************/
void iTree::PrintITree(t_INode* root)
{
    if( NULL == root)
    {
        return;
    }
    else
    {
        std::cout<<"index:"<<root->dimension_index_<<"data_size:"
            <<root->node_size_<<"split_value:"<<root->split_value_<<std::endl;
        PrintITree(root->left_node_);
        PrintITree(root->right_node_);
    }
}


//------------------------------------------------------------------------------
//搜索itree
//------------------------------------------------------------------------------
double iTree::SearchInstance(t_Data data_point,
                             t_INode* root,
                             int height)
{
    //if is the leaf node
    if( (NULL == root->left_node_ && NULL == root->right_node_))
    {
        //密度比，方差比
        //return 1/((double)root->parent_node_->variance_ / root->variance_);
        if( root->parent_node_ != NULL)
        {
//            return  root->variance_/(double)root->parent_node_->variance_;
            return height;
        }
        else
        {
            return 1;
        }
    }

    //Search left subtree and right subtree
    if(data_point.attribute_[root->dimension_index_]< root->split_value_)
    {
        return SearchInstance(data_point,root->left_node_,height+1);
    }
    else
    {
        return SearchInstance(data_point,root->right_node_,height+1);
    }
}

//search all instance,return search score
std::vector<t_AnomalyScore> iTree::SearchAll()
{
  std::vector<t_Data> data_set = data_procession_->GetNormalizedDataSet();
  std::vector<t_AnomalyScore> score_set;
  int data_size = data_set.size();

  //search
  for ( unsigned i = 0 ; i < data_size;i++ )
    {
      double height_temp;
      t_Data data_temp = data_set[i];
      t_AnomalyScore score_temp;

      height_temp = SearchInstance(data_temp,itree_root_,0);
      score_temp.class_label_ = data_temp.data_class_;
      score_temp.data_index_ = i;
      score_temp.score_ = height_temp;
      score_set.push_back(score_temp);
    }

  return score_set;
}

