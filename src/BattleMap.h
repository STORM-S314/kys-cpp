#pragma once
#include "BattleData.h"
#include "Scene.h"
#include "Point.h"
#include <stack>

class BattleMap : public Scene
{
public:
    BattleMap();
    ~BattleMap();

	void init();
    virtual void draw() override;
    virtual void dealEvent(BP_Event& e) override;


    int MaxSceneCoord = 63;
    static const int m_nMaxBRoleSelect = 6;       //ս��ѡ���������
    int m_nMaxBRoleNum = 42;                      //���ս����ս����

    const int m_nbattleSpeed = 0.025;             //ս���ٶ�
    int m_nBx = 31, m_nBy = 31;                                //��ǰλ��
    int m_nAx, m_nAy;                                //Ŀ��λ��
    int m_nlinex[480 * 480], m_nliney[480 * 480];
    int m_nmanPicture;
    int m_nstep = 0;
    int m_ncurA;
    int m_ncounter = 0;                           // �������������ѡ���߼�����
    int m_nxx = 317;                              // ������Ϣ�����x
    int m_nyy = 382;                              // ������Ϣ�����y
    enum
    {
        kindOfRole = 7                         //������Ϣ�������������
    };
    std::string m_strList[BattleMap::kindOfRole];    // ������Ϣ��������ԣ�Ĭ���������������������Ṧ��
    int m_nList = 0;                          // ������Ϣ������б�λ��
    int m_nOffset_BRolePic = 1;                   //����ս��ͼ����
    int m_nBRoleAmount = 0;                       //ս������
    int m_nMods = 0;                              //ս��ģʽ
    std::string m_strMenuString[m_nMaxBRoleSelect + 2];     //ս������ѡ��
    int m_nMax0;                                  //�������
    int m_nMaxspeed;                              //�����

    int m_nBStatus;
    bool m_bisBattle;
    int m_nWhere;
    int m_ncurRoleNum;                            //��ǰ�������
    int m_nBattleList[m_nMaxBRoleSelect];            //��ս��Ա�б�
    int m_nResultofBattle[m_nMaxBRoleSelect];        //ս��ѡ�˽��
    //MenuItemFont* item[maxBRoleSelect + 2];                                 //ѡ�˿ؼ�
    bool m_bSlectOfresult[m_nMaxBRoleSelect + 2];    //ѡ��״̬
    int m_nbattleNum;                             //��ǰս����
    int m_nbattleSceneNum = 0;                        //��ǰս��������
    int m_ncurMagic;                              //��ǰ�书

    //std::vector<Sprite*> EarthS, BuildS, AirS, EventS;
    std::stack<Point> m_wayQue;                       //ջ(·��ջ)


    BattleData& Battle = BattleData::m_bBattle;  //����battle
    //vector<battle::TBattleRole> BRole;   //����ս����Ա
    std::vector<BattleSceneData>& m_vcBattleSceneData = BattleData::getInstance()->m_vcBattleSceneData;
    std::vector<BattleRole>& m_vcBattleRole = BattleData::getInstance()->m_vcBattleRole;
    std::vector<BattleInfo>& m_vcBattleInfo = BattleData::getInstance()->m_vcBattleInfo;
	//std::vector<Character>& Rrole = Save::getInstance()->m_Character;

    void walk(int x, int y, Towards t);

    void checkTimer2();
    void callEvent(int x, int y);
    bool canWalk(int x, int y);
    virtual bool checkIsBuilding(int x, int y);
    virtual bool checkIsOutLine(int x, int y);

    bool checkIsHinder(int x, int y);
    bool checkIsEvent(int x, int y);
    bool checkIsFall(int x, int y);
    bool checkIsExit(int x, int y);
    bool checkIsOutScreen(int x, int y);

    void initData(int battlenum);
    bool initBattleData();
    bool initBattleRoleState();
    bool autoInBattle();

    void autoSetMagic(int rnum);
    int selectTeamMembers();
    void ShowMultiMenu(int max0, int menu);
    void showSlectMenu(std::string* str, int x);                               // ��ս������Ϣ
    void showBattleMenu(int x, int y);                                    // ս������

    void initMultiMenu();

    void getMousePosition(Point* point);
    virtual void FindWay(int Mx, int My, int Fx, int Fy);

    int CallFace(int x1, int y1, int x2, int y2);

    //void menuCloseCallback(Ref* pSender);
    //void menuCloseCallback1(Ref* pSender);
    bool battle(int battlenum, int getexp, int mods, int id, int maternum, int enemyrnum);
    void setInitState(int& n0);
    void calMoveAbility();
    void reArrangeBRole();
    int getRoleSpeed(int rnum, bool Equip);
    int getGongtiLevel(int rnum);
    float power(float base, float Exponent);
    void moveRole(int bnum);
    void calCanSelect(int bnum, int mode, int step);
    void seekPath2(int x, int y, int step, int myteam, int mode);
    void moveAmination(int bnum);
    bool selectAim(int bnum, int step, int mods);
    void battleMainControl();
    void battleMainControl(int mods, int id);
    //void Draw(float dt);
    void moveAminationStep(float dt);
    void attack(int bum);
};