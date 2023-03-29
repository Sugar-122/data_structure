//基于顺序表实现线性表
#include<iostream>
using namespace std;
const int MAXN=100;
class SeqList{
    public:
        int data[MAXN];
        int length;
        //无参构造函数
        SeqList(){
            length=0;
        }

        //有参构造函数
        SeqList(int a[],int n);

        //析构函数
        ~SeqList(){
            cout<<"线性表已销毁！"<<endl;
        }

        //判断线性表是否为空
        bool SeqEmpty();

        //清空线性表
        void SeqClear();

        //查找固定数据
        int SeqGet(int i);

        //查找线性表中是否有目标数据，若有返回数据序号
        int SeqLocation(int elem);
        
        //在第i个位置插入新元素
        void SeqInsert(int i,int elem);
        
        //删除第i个位置的元素
        void SeqDelete(int i);

        //返回线性表长度
        int SeqLength();

        //打印线性表内容
        void SeqPrint();
};

SeqList::SeqList(int a[],int n){
    if(n>MAXN){
        cout<<"Error: 内存不足,数组越界..."<<endl;
    }
    for(int i=0;i<n;i++){
        data[i]=a[i];
    }
    length=n;
    cout<<"构造线性表完毕！"<<endl;
}

//判断线性表是否为空
bool SeqList::SeqEmpty(){
    //线性表为空
    if(length==0){
        return true;
    }
    //线性表不为空
    else{
        return false;
    }
}

//清空线性表
//感觉这里我的做法有点问题，我就是把数组里面的所有值变为0，length=0
void SeqList::SeqClear(){
    for(int i=0;i<this->length;i++){
        this->data[i]=0;
    }
    this->length=0;
}

//查找线性表中第i个数据，并且返回
int SeqList::SeqGet(int i){
    if(i<1||i>this->length){
        cout<<"Error: 越界！！！不可访问地址..."<<endl;
        return 0;
    }
    else
        return this->data[i-1];
}

//查找线性表中是否有目标数据,并且返回数据序号
int SeqList::SeqLocation(int elem){
    for(int i=0;i<this->length;i++){
        if(this->data[i]==elem){
            return i+1;
        }
    }
    return 0;
}


//在第i个位置插入新元素
void SeqList::SeqInsert(int i,int elem){
    if(i<1||i>this->length){
        cout<<"Error:越界！！！不可访问地址..."<<endl;
    }
    for(int j=length;j>=i;j--){
        //移位
        this->data[j]=this->data[j-1];
    }
    this->data[i-1]=elem;
    this->length++;
}

//删除第i个位置的元素
void SeqList::SeqDelete(int i){
    if(i<1||i>this->length){
        cout<<"Error:越界！！！不可访问地址..."<<endl;
    }
    for(int j=i-1;j<length-1;j++){
        this->data[j]=data[j+1];
    }
    this->length--;
}

//返回线性表长度
int SeqList::SeqLength(){
    return this->length;
}

//打印线性表内容
void SeqList::SeqPrint(){
    if(this->length!=0){
        for(int i=0;i<length;i++){
            cout<<data[i]<<" ";
        }
        cout<<endl;
    }
    else{
        cout<<"线性表为空..."<<endl;
    }

}
int main(){
    int a[10]={1,2,3,4,5,6,7,8,9,10};
    cout<<"---开始构造线性表..."<<endl;
    SeqList list(a,10);
    cout<<"---打印线性表内容..."<<endl;
    list.SeqPrint();
    cout<<"---检测当前线性表是否为空..."<<endl;
    if(list.SeqEmpty())
        cout<<"当前线性表为空!"<<endl;
    else
        cout<<"当前线性表不为空!"<<endl;
    cout<<"---检测当前线性表长度..."<<endl;
    cout<<"当前线性表长度为："<<list.SeqLength()<<endl;
    cout<<"---检测能否正常插入..."<<endl;
    cout<<"---在第2个位置插入数据测试数据666"<<endl;
    list.SeqInsert(2,666);
    cout<<"查看插入后结果..."<<endl;
    list.SeqPrint();
    cout<<"当前线性表的长度为: "<<list.SeqLength()<<endl;
    cout<<"---查看当前线性表是否有目标数值,若有则返回其所在位置,0则代表不存在.."<<endl;
    cout<<"查看是否存在666"<<endl;
    cout<<list.SeqLocation(666)<<endl;
    cout<<"查看是否存在250"<<endl;
    cout<<list.SeqLocation(250)<<endl;
    cout<<"---测试是否能够正常删除..."<<endl;
    cout<<"删除第二个元素..."<<endl;
    cout<<"未删除之前的线性表为：";
    list.SeqPrint();
    cout<<"删除之前的线性表长度为："<<list.SeqLength()<<endl;
    list.SeqDelete(2);
    cout<<"删除之后的线性表为: ";
    list.SeqPrint();
    cout<<"删除之后的线性表长度为："<<list.SeqLength()<<endl;
    cout<<"---测试能否正常清空..."<<endl;
    list.SeqClear();
    list.SeqPrint();

    return 0;
}