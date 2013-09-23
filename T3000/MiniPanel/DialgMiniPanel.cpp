// DialgMiniPanel.cpp : implementation file
//

#include "stdafx.h"
#include "DialgMiniPanel.h"
#include "../globle_function.h"
#include "../T3000.h"

static BOOL ifminidb = TRUE;

// CDialgMiniPanel

IMPLEMENT_DYNCREATE(CDialgMiniPanel, CFormView)


CDialgMiniPanel::CDialgMiniPanel()
	: CFormView(CDialgMiniPanel::IDD)
	, m_inaddress(0)
	, m_inSerialNum(0)
	, m_flFirmware(0)
	, m_inHardware(0)
	, m_CStrModel(_T(""))
	, m_inBaudrate(0)
	, m_datetime(_T(""))
{

}

CDialgMiniPanel::~CDialgMiniPanel()
{
}

void CDialgMiniPanel::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MSFLEXGRID_INPUT, m_msflexgridinput);
	DDX_Control(pDX, IDC_MSFLEXGRID_OUTPUT_DO, m_msflexgridDO);
	DDX_Control(pDX, IDC_MSFLEXGRID_OUTPUT_AO, m_msflexgridAO);
	DDX_Text(pDX, IDC_EDIT1, m_inaddress);
	DDX_Text(pDX, IDC_EDIT3, m_inSerialNum);
	DDX_Text(pDX, IDC_EDIT2, m_flFirmware);
	DDX_Text(pDX, IDC_EDIT4, m_inHardware);
	DDX_Text(pDX, IDC_EDIT5, m_CStrModel);
	DDX_Text(pDX, IDC_EDIT6, m_inBaudrate);
	DDX_Text(pDX, IDC_STATIC1, m_datetime);
	DDX_Text(pDX, IDC_STATIC1, m_datetime);
	DDX_Control(pDX, IDC_EDIT_INPUT, m_editinput);
	DDX_Control(pDX, IDC_EDITOUTPUTDO, m_editoutputdo);
	DDX_Control(pDX, IDC_EDIT_OUTPUTAO, m_editoutputao);
}

BEGIN_MESSAGE_MAP(CDialgMiniPanel, CFormView)
	ON_WM_TIMER()
	ON_EN_KILLFOCUS(IDC_EDIT_INPUT, &CDialgMiniPanel::OnEnKillfocusEditInput)
	ON_EN_KILLFOCUS(IDC_EDITOUTPUTDO, &CDialgMiniPanel::OnEnKillfocusEditoutputdo)
	ON_EN_KILLFOCUS(IDC_EDIT_OUTPUTAO, &CDialgMiniPanel::OnEnKillfocusEditOutputao)
END_MESSAGE_MAP()


// CDialgMiniPanel diagnostics

#ifdef _DEBUG
void CDialgMiniPanel::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CDialgMiniPanel::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG

int  CDialgMiniPanel::Get_RegID(CString Name)
{
	Name.TrimLeft();
	Name.TrimRight();
	int regid=-1;
	vector<T3Register>::iterator iter;
	for (iter=m_vecT3Register.begin();iter!=m_vecT3Register.end();iter++)
	{
		if (iter->regName==Name)
		{
			regid=iter->regID;
			break;
		}
	}
	return regid;
}
void CDialgMiniPanel::Initial_RegisterList(){
#if 1
	SN_LOW	=	0	;

	SN_HI	=	2	;

	FIRMWARE_VER_NUMBER_0	=	4	;
	FIRMWARE_VER_NUMBER_1	=	5	;
	MODBUS_ID	=	6	;
	PRODUCT_MODEL	=	7	;
	HARDWARE_VER_NUMBER	=	8	;
	BAUDRATE	=	9	;
	CALIBRATION	=	10	;
	PLUG_N_PLAY	=	13	;
	VER_ISP	=	14	;

	UPDATE_STATUS	=	16	;
	PROTOCAL_TYPE	=	17	;
	DIGITAL_OUTPUT1	=	100	;
	DIGITAL_OUTPUT2	=	101	;
	DIGITAL_OUTPUT3	=	102	;
	DIGITAL_OUTPUT4	=	103	;
	DIGITAL_OUTPUT5	=	104	;
	DIGITAL_OUTPUT6	=	105	;
	DIGITAL_OUTPUT7	=	106	;
	DIGITAL_OUTPUT8	=	107	;
	DIGITAL_OUTPUT9	=	108	;
	DIGITAL_OUTPUT10	=	109	;
	DIGITAL_OUTPUT11	=	110	;
	DIGITAL_OUTPUT12	=	111	;
	ANALOG_OUTPUT1	=	112	;
	ANALOG_OUTPUT2	=	113	;
	ANALOG_OUTPUT3	=	114	;
	ANALOG_OUTPUT4	=	115	;
	ANALOG_OUTPUT5	=	116	;
	ANALOG_OUTPUT6	=	117	;
	ANALOG_OUTPUT7	=	118	;
	ANALOG_OUTPUT8	=	119	;
	ANALOG_OUTPUT9	=	120	;
	ANALOG_OUTPUT10	=	121	;
	ANALOG_OUTPUT11	=	122	;
	ANALOG_OUTPUT12	=	123	;
	SWITCH_STATUS1	=	124	;
	SWITCH_STATUS2	=	125	;
	SWITCH_STATUS3	=	126	;
	SWITCH_STATUS4	=	127	;
	SWITCH_STATUS5	=	128	;
	SWITCH_STATUS6	=	129	;
	SWITCH_STATUS7	=	130	;
	SWITCH_STATUS8	=	131	;
	SWITCH_STATUS9	=	132	;
	SWITCH_STATUS10	=	133	;
	SWITCH_STATUS11	=	134	;
	SWITCH_STATUS12	=	135	;
	SWITCH_STATUS13	=	136	;
	SWITCH_STATUS14	=	137	;
	SWITCH_STATUS15	=	138	;
	SWITCH_STATUS16	=	139	;
	SWITCH_STATUS17	=	140	;
	SWITCH_STATUS18	=	141	;
	SWITCH_STATUS19	=	142	;
	SWITCH_STATUS20	=	143	;
	SWITCH_STATUS21	=	144	;
	SWITCH_STATUS22	=	145	;
	SWITCH_STATUS23	=	146	;
	SWITCH_STATUS24	=	147	;
	INPUT1	=	148	;
	INPUT2	=	149	;
	INPUT3	=	150	;
	INPUT4	=	151	;
	INPUT5	=	152	;
	INPUT6	=	153	;
	INPUT7	=	154	;
	INPUT8	=	155	;
	INPUT9	=	156	;
	INPUT10	=	157	;
	INPUT11	=	158	;
	INPUT12	=	159	;
	INPUT13	=	160	;
	INPUT14	=	161	;
	INPUT15	=	162	;
	INPUT16	=	163	;
	INPUT17	=	164	;
	INPUT18	=	165	;
	INPUT19	=	166	;
	INPUT20	=	167	;
	INPUT21	=	168	;
	INPUT22	=	169	;
	INPUT23	=	170	;
	INPUT24	=	171	;
	INPUT25	=	172	;
	INPUT26	=	173	;
	INPUT27	=	174	;
	INPUT28	=	175	;
	INPUT29	=	176	;
	INPUT30	=	177	;
	INPUT31	=	178	;
	INPUT32	=	179	;
	LOW_VOLTAGE	=	180	;
	INPUT_UNIT1	=	181	;
	INPUT_UNIT2	=	182	;
	INPUT_UNIT3	=	183	;
	INPUT_UNIT4	=	184	;
	INPUT_UNIT5	=	185	;
	INPUT_UNIT6	=	186	;
	INPUT_UNIT7	=	187	;
	INPUT_UNIT8	=	188	;
	INPUT_UNIT9	=	189	;
	INPUT_UNIT10	=	190	;
	INPUT_UNIT11	=	191	;
	INPUT_UNIT12	=	192	;
	INPUT_UNIT13	=	193	;
	INPUT_UNIT14	=	194	;
	INPUT_UNIT15	=	195	;
	INPUT_UNIT16	=	196	;
	INPUT_UNIT17	=	197	;
	INPUT_UNIT18	=	198	;
	INPUT_UNIT19	=	199	;
	INPUT_UNIT20	=	200	;
	INPUT_UNIT21	=	201	;
	INPUT_UNIT22	=	202	;
	INPUT_UNIT23	=	203	;
	INPUT_UNIT24	=	204	;
	INPUT_UNIT25	=	205	;
	INPUT_UNIT26	=	206	;
	INPUT_UNIT27	=	207	;
	INPUT_UNIT28	=	208	;
	INPUT_UNIT29	=	209	;
	INPUT_UNIT30	=	210	;
	INPUT_UNIT31	=	211	;
	INPUT_UNIT32	=	212	;
	LOW_VOLTAGE_UNIT	=	213	;
	HIGHER_BYTE_YEAR	=	300	;
	LOWER_BYTE_YEAR	=	301	;
	MONTH	=	302	;
	WEEK	=	303	;
	DAY	=	304	;
	HOUR	=	305	;
	MINUTE	=	306	;
	SECOND	=	307	;
	WEEKLY_ROUTINE_620	=	308	;
	ANNUAL_ROUTINE_464	=	928	;
	ID_SCHEDULE_762	=	1392	;
	ANNUAL_ROUTINE_TIME_736	=	2154	;
	WEEKLY_ROUTINE_ONTIME_1440	=	2890	;
	WEEKLY_ROUTINE_OFFTIME_1440	=	4330	;
	TSTAT_OCCUPIEDSTATUS_SUBTSTATS	=	5670	;
	TSTAT_COOLINGSETPOINT_SUBTSTATS	=	5671	;
	TSTAT_HEATINGSETPOINT_SUBTSTATS	=	5679	;
	TSTAT_SETPOINT_SUBTSTATS	=	5687	;
	TSTAT_TEMPERATURE_SUBTSTATS	=	5695	;
	TSTAT_MODE_SUBTSTATS	=	5703	;
	TSTAT_OUTPUTSTATE_SUBTSTATS	=	5711	;
	TSTAT_NIGHT_HEATTINGDB_SUBTSTATS	=	5719	;
	TSTAT_NIGHT_COOLINGDB_SUBTSTATS	=	5727	;
	TSTAT_NIGHT_HEATTINGSETPOINT_SUBTSTATS	=	5735	;
	TSTAT_NIGHT_COOLINGSETPOINT_SUBTSTATS	=	5743	;
	TSTAT_PRODUCTMODEL_SUBTSTATS	=	5751	;
	TSTAT_OVERRIDE_SUBTSTATS	=	5759	;
	TSTAT_SERIALNO_SUBTSTATS	=	5767	;
	TSTAT_OFFTIME_SUBTSTATS	=	5800	;
	TSTAT_ONTIME_SUBTSTATS	=	6100	;
	TEST50	=	7000	;
	VALUEINPUT1TO34	=	8000	;
	RANGE_INPUT1TO32	=	8034	;
	FILTER_INPUT1TO32	=	8066	;
	CALIBRATION_INPUT1TO32	=	8098	;
	TOTAL_TSTAT0	=	8200	;
	TOTAL_TSTAT1	=	8201	;
	TOTAL_TSTAT2	=	8202	;
	TSTAT_ADD_BOTH_CHANNEL_UART0	=	8203	;
	TSTAT_ADD_BOTH_CHANNEL_UART1	=	8303	;
	TSTAT_ADD_BOTH_CHANNEL_UART2	=	8403	;
	
#endif
		T3Register temp;
		CADO m_ado;
		m_ado.OnInitADOConn();
#if 1
		CString SQL = _T("select * from MiniPanel_Registerlist");
		m_ado.m_pRecordset = m_ado.OpenRecordset(SQL);
		_variant_t vartemp;
		while(!m_ado.m_pRecordset->EndOfFile)
		{
			temp.regID=m_ado.m_pRecordset->GetCollect(_T("RegID"));
			vartemp =m_ado.m_pRecordset->GetCollect(_T("Reg_Name"));
			if (vartemp.vt==VT_NULL)
				temp.regName=_T("");
			else
				temp.regName =vartemp;
			m_ado.m_pRecordset->MoveNext();
			m_vecT3Register.push_back(temp);
		}
		m_ado.CloseRecordset();
		m_ado.CloseConn();
#endif 


#if 1
		SN_LOW	=	Get_RegID(_T("	SN_LOW	"))	;
	
		SN_HI	=	Get_RegID(_T("	SN_HI	"))	;
	
		FIRMWARE_VER_NUMBER_0	=	Get_RegID(_T("	FIRMWARE_VER_NUMBER_0	"))	;
		FIRMWARE_VER_NUMBER_1	=	Get_RegID(_T("	FIRMWARE_VER_NUMBER_1	"))	;
		MODBUS_ID	=	Get_RegID(_T("	MODBUS_ID	"))	;
		PRODUCT_MODEL	=	Get_RegID(_T("	PRODUCT_MODEL	"))	;
		HARDWARE_VER_NUMBER	=	Get_RegID(_T("	HARDWARE_VER_NUMBER	"))	;
		BAUDRATE	=	Get_RegID(_T("	BAUDRATE	"))	;
		CALIBRATION	=	Get_RegID(_T("	CALIBRATION	"))	;
		PLUG_N_PLAY	=	Get_RegID(_T("	PLUG_N_PLAY	"))	;
		VER_ISP	=	Get_RegID(_T("	VER_ISP	"))	;
	
		UPDATE_STATUS	=	Get_RegID(_T("	UPDATE_STATUS	"))	;
		PROTOCAL_TYPE	=	Get_RegID(_T("	PROTOCAL_TYPE	"))	;
		DIGITAL_OUTPUT1	=	Get_RegID(_T("	DIGITAL_OUTPUT1	"))	;
		DIGITAL_OUTPUT2	=	Get_RegID(_T("	DIGITAL_OUTPUT2	"))	;
		DIGITAL_OUTPUT3	=	Get_RegID(_T("	DIGITAL_OUTPUT3	"))	;
		DIGITAL_OUTPUT4	=	Get_RegID(_T("	DIGITAL_OUTPUT4	"))	;
		DIGITAL_OUTPUT5	=	Get_RegID(_T("	DIGITAL_OUTPUT5	"))	;
		DIGITAL_OUTPUT6	=	Get_RegID(_T("	DIGITAL_OUTPUT6	"))	;
		DIGITAL_OUTPUT7	=	Get_RegID(_T("	DIGITAL_OUTPUT7	"))	;
		DIGITAL_OUTPUT8	=	Get_RegID(_T("	DIGITAL_OUTPUT8	"))	;
		DIGITAL_OUTPUT9	=	Get_RegID(_T("	DIGITAL_OUTPUT9	"))	;
		DIGITAL_OUTPUT10	=	Get_RegID(_T("	DIGITAL_OUTPUT10	"))	;
		DIGITAL_OUTPUT11	=	Get_RegID(_T("	DIGITAL_OUTPUT11	"))	;
		DIGITAL_OUTPUT12	=	Get_RegID(_T("	DIGITAL_OUTPUT12	"))	;
		ANALOG_OUTPUT1	=	Get_RegID(_T("	ANALOG_OUTPUT1	"))	;
		ANALOG_OUTPUT2	=	Get_RegID(_T("	ANALOG_OUTPUT2	"))	;
		ANALOG_OUTPUT3	=	Get_RegID(_T("	ANALOG_OUTPUT3	"))	;
		ANALOG_OUTPUT4	=	Get_RegID(_T("	ANALOG_OUTPUT4	"))	;
		ANALOG_OUTPUT5	=	Get_RegID(_T("	ANALOG_OUTPUT5	"))	;
		ANALOG_OUTPUT6	=	Get_RegID(_T("	ANALOG_OUTPUT6	"))	;
		ANALOG_OUTPUT7	=	Get_RegID(_T("	ANALOG_OUTPUT7	"))	;
		ANALOG_OUTPUT8	=	Get_RegID(_T("	ANALOG_OUTPUT8	"))	;
		ANALOG_OUTPUT9	=	Get_RegID(_T("	ANALOG_OUTPUT9	"))	;
		ANALOG_OUTPUT10	=	Get_RegID(_T("	ANALOG_OUTPUT10	"))	;
		ANALOG_OUTPUT11	=	Get_RegID(_T("	ANALOG_OUTPUT11	"))	;
		ANALOG_OUTPUT12	=	Get_RegID(_T("	ANALOG_OUTPUT12	"))	;
		SWITCH_STATUS1	=	Get_RegID(_T("	SWITCH_STATUS1	"))	;
		SWITCH_STATUS2	=	Get_RegID(_T("	SWITCH_STATUS2	"))	;
		SWITCH_STATUS3	=	Get_RegID(_T("	SWITCH_STATUS3	"))	;
		SWITCH_STATUS4	=	Get_RegID(_T("	SWITCH_STATUS4	"))	;
		SWITCH_STATUS5	=	Get_RegID(_T("	SWITCH_STATUS5	"))	;
		SWITCH_STATUS6	=	Get_RegID(_T("	SWITCH_STATUS6	"))	;
		SWITCH_STATUS7	=	Get_RegID(_T("	SWITCH_STATUS7	"))	;
		SWITCH_STATUS8	=	Get_RegID(_T("	SWITCH_STATUS8	"))	;
		SWITCH_STATUS9	=	Get_RegID(_T("	SWITCH_STATUS9	"))	;
		SWITCH_STATUS10	=	Get_RegID(_T("	SWITCH_STATUS10	"))	;
		SWITCH_STATUS11	=	Get_RegID(_T("	SWITCH_STATUS11	"))	;
		SWITCH_STATUS12	=	Get_RegID(_T("	SWITCH_STATUS12	"))	;
		SWITCH_STATUS13	=	Get_RegID(_T("	SWITCH_STATUS13	"))	;
		SWITCH_STATUS14	=	Get_RegID(_T("	SWITCH_STATUS14	"))	;
		SWITCH_STATUS15	=	Get_RegID(_T("	SWITCH_STATUS15	"))	;
		SWITCH_STATUS16	=	Get_RegID(_T("	SWITCH_STATUS16	"))	;
		SWITCH_STATUS17	=	Get_RegID(_T("	SWITCH_STATUS17	"))	;
		SWITCH_STATUS18	=	Get_RegID(_T("	SWITCH_STATUS18	"))	;
		SWITCH_STATUS19	=	Get_RegID(_T("	SWITCH_STATUS19	"))	;
		SWITCH_STATUS20	=	Get_RegID(_T("	SWITCH_STATUS20	"))	;
		SWITCH_STATUS21	=	Get_RegID(_T("	SWITCH_STATUS21	"))	;
		SWITCH_STATUS22	=	Get_RegID(_T("	SWITCH_STATUS22	"))	;
		SWITCH_STATUS23	=	Get_RegID(_T("	SWITCH_STATUS23	"))	;
		SWITCH_STATUS24	=	Get_RegID(_T("	SWITCH_STATUS24	"))	;
		INPUT1	=	Get_RegID(_T("	INPUT1	"))	;
		INPUT2	=	Get_RegID(_T("	INPUT2	"))	;
		INPUT3	=	Get_RegID(_T("	INPUT3	"))	;
		INPUT4	=	Get_RegID(_T("	INPUT4	"))	;
		INPUT5	=	Get_RegID(_T("	INPUT5	"))	;
		INPUT6	=	Get_RegID(_T("	INPUT6	"))	;
		INPUT7	=	Get_RegID(_T("	INPUT7	"))	;
		INPUT8	=	Get_RegID(_T("	INPUT8	"))	;
		INPUT9	=	Get_RegID(_T("	INPUT9	"))	;
		INPUT10	=	Get_RegID(_T("	INPUT10	"))	;
		INPUT11	=	Get_RegID(_T("	INPUT11	"))	;
		INPUT12	=	Get_RegID(_T("	INPUT12	"))	;
		INPUT13	=	Get_RegID(_T("	INPUT13	"))	;
		INPUT14	=	Get_RegID(_T("	INPUT14	"))	;
		INPUT15	=	Get_RegID(_T("	INPUT15	"))	;
		INPUT16	=	Get_RegID(_T("	INPUT16	"))	;
		INPUT17	=	Get_RegID(_T("	INPUT17	"))	;
		INPUT18	=	Get_RegID(_T("	INPUT18	"))	;
		INPUT19	=	Get_RegID(_T("	INPUT19	"))	;
		INPUT20	=	Get_RegID(_T("	INPUT20	"))	;
		INPUT21	=	Get_RegID(_T("	INPUT21	"))	;
		INPUT22	=	Get_RegID(_T("	INPUT22	"))	;
		INPUT23	=	Get_RegID(_T("	INPUT23	"))	;
		INPUT24	=	Get_RegID(_T("	INPUT24	"))	;
		INPUT25	=	Get_RegID(_T("	INPUT25	"))	;
		INPUT26	=	Get_RegID(_T("	INPUT26	"))	;
		INPUT27	=	Get_RegID(_T("	INPUT27	"))	;
		INPUT28	=	Get_RegID(_T("	INPUT28	"))	;
		INPUT29	=	Get_RegID(_T("	INPUT29	"))	;
		INPUT30	=	Get_RegID(_T("	INPUT30	"))	;
		INPUT31	=	Get_RegID(_T("	INPUT31	"))	;
		INPUT32	=	Get_RegID(_T("	INPUT32	"))	;
		LOW_VOLTAGE	=	Get_RegID(_T("	LOW_VOLTAGE	"))	;
		INPUT_UNIT1	=	Get_RegID(_T("	INPUT_UNIT1	"))	;
		INPUT_UNIT2	=	Get_RegID(_T("	INPUT_UNIT2	"))	;
		INPUT_UNIT3	=	Get_RegID(_T("	INPUT_UNIT3	"))	;
		INPUT_UNIT4	=	Get_RegID(_T("	INPUT_UNIT4	"))	;
		INPUT_UNIT5	=	Get_RegID(_T("	INPUT_UNIT5	"))	;
		INPUT_UNIT6	=	Get_RegID(_T("	INPUT_UNIT6	"))	;
		INPUT_UNIT7	=	Get_RegID(_T("	INPUT_UNIT7	"))	;
		INPUT_UNIT8	=	Get_RegID(_T("	INPUT_UNIT8	"))	;
		INPUT_UNIT9	=	Get_RegID(_T("	INPUT_UNIT9	"))	;
		INPUT_UNIT10	=	Get_RegID(_T("	INPUT_UNIT10	"))	;
		INPUT_UNIT11	=	Get_RegID(_T("	INPUT_UNIT11	"))	;
		INPUT_UNIT12	=	Get_RegID(_T("	INPUT_UNIT12	"))	;
		INPUT_UNIT13	=	Get_RegID(_T("	INPUT_UNIT13	"))	;
		INPUT_UNIT14	=	Get_RegID(_T("	INPUT_UNIT14	"))	;
		INPUT_UNIT15	=	Get_RegID(_T("	INPUT_UNIT15	"))	;
		INPUT_UNIT16	=	Get_RegID(_T("	INPUT_UNIT16	"))	;
		INPUT_UNIT17	=	Get_RegID(_T("	INPUT_UNIT17	"))	;
		INPUT_UNIT18	=	Get_RegID(_T("	INPUT_UNIT18	"))	;
		INPUT_UNIT19	=	Get_RegID(_T("	INPUT_UNIT19	"))	;
		INPUT_UNIT20	=	Get_RegID(_T("	INPUT_UNIT20	"))	;
		INPUT_UNIT21	=	Get_RegID(_T("	INPUT_UNIT21	"))	;
		INPUT_UNIT22	=	Get_RegID(_T("	INPUT_UNIT22	"))	;
		INPUT_UNIT23	=	Get_RegID(_T("	INPUT_UNIT23	"))	;
		INPUT_UNIT24	=	Get_RegID(_T("	INPUT_UNIT24	"))	;
		INPUT_UNIT25	=	Get_RegID(_T("	INPUT_UNIT25	"))	;
		INPUT_UNIT26	=	Get_RegID(_T("	INPUT_UNIT26	"))	;
		INPUT_UNIT27	=	Get_RegID(_T("	INPUT_UNIT27	"))	;
		INPUT_UNIT28	=	Get_RegID(_T("	INPUT_UNIT28	"))	;
		INPUT_UNIT29	=	Get_RegID(_T("	INPUT_UNIT29	"))	;
		INPUT_UNIT30	=	Get_RegID(_T("	INPUT_UNIT30	"))	;
		INPUT_UNIT31	=	Get_RegID(_T("	INPUT_UNIT31	"))	;
		INPUT_UNIT32	=	Get_RegID(_T("	INPUT_UNIT32	"))	;
		LOW_VOLTAGE_UNIT	=	Get_RegID(_T("	LOW_VOLTAGE_UNIT	"))	;
		HIGHER_BYTE_YEAR	=	Get_RegID(_T("	HIGHER_BYTE_YEAR	"))	;
		LOWER_BYTE_YEAR	=	Get_RegID(_T("	LOWER_BYTE_YEAR	"))	;
		MONTH	=	Get_RegID(_T("	MONTH	"))	;
		WEEK	=	Get_RegID(_T("	WEEK	"))	;
		DAY	=	Get_RegID(_T("	DAY	"))	;
		HOUR	=	Get_RegID(_T("	HOUR	"))	;
		MINUTE	=	Get_RegID(_T("	MINUTE	"))	;
		SECOND	=	Get_RegID(_T("	SECOND	"))	;
		WEEKLY_ROUTINE_620	=	Get_RegID(_T("	WEEKLY_ROUTINE_620	"))	;
		ANNUAL_ROUTINE_464	=	Get_RegID(_T("	ANNUAL_ROUTINE_464	"))	;
		ID_SCHEDULE_762	=	Get_RegID(_T("	ID_SCHEDULE_762	"))	;
		ANNUAL_ROUTINE_TIME_736	=	Get_RegID(_T("	ANNUAL_ROUTINE_TIME_736	"))	;
		WEEKLY_ROUTINE_ONTIME_1440	=	Get_RegID(_T("	WEEKLY_ROUTINE_ONTIME_1440	"))	;
		WEEKLY_ROUTINE_OFFTIME_1440	=	Get_RegID(_T("	WEEKLY_ROUTINE_OFFTIME_1440	"))	;
		TSTAT_OCCUPIEDSTATUS_SUBTSTATS	=	Get_RegID(_T("	TSTAT_OCCUPIEDSTATUS_SUBTSTATS	"))	;
		TSTAT_COOLINGSETPOINT_SUBTSTATS	=	Get_RegID(_T("	TSTAT_COOLINGSETPOINT_SUBTSTATS	"))	;
		TSTAT_HEATINGSETPOINT_SUBTSTATS	=	Get_RegID(_T("	TSTAT_HEATINGSETPOINT_SUBTSTATS	"))	;
		TSTAT_SETPOINT_SUBTSTATS	=	Get_RegID(_T("	TSTAT_SETPOINT_SUBTSTATS	"))	;
		TSTAT_TEMPERATURE_SUBTSTATS	=	Get_RegID(_T("	TSTAT_TEMPERATURE_SUBTSTATS	"))	;
		TSTAT_MODE_SUBTSTATS	=	Get_RegID(_T("	TSTAT_MODE_SUBTSTATS	"))	;
		TSTAT_OUTPUTSTATE_SUBTSTATS	=	Get_RegID(_T("	TSTAT_OUTPUTSTATE_SUBTSTATS	"))	;
		TSTAT_NIGHT_HEATTINGDB_SUBTSTATS	=	Get_RegID(_T("	TSTAT_NIGHT_HEATTINGDB_SUBTSTATS	"))	;
		TSTAT_NIGHT_COOLINGDB_SUBTSTATS	=	Get_RegID(_T("	TSTAT_NIGHT_COOLINGDB_SUBTSTATS	"))	;
		TSTAT_NIGHT_HEATTINGSETPOINT_SUBTSTATS	=	Get_RegID(_T("	TSTAT_NIGHT_HEATTINGSETPOINT_SUBTSTATS	"))	;
		TSTAT_NIGHT_COOLINGSETPOINT_SUBTSTATS	=	Get_RegID(_T("	TSTAT_NIGHT_COOLINGSETPOINT_SUBTSTATS	"))	;
		TSTAT_PRODUCTMODEL_SUBTSTATS	=	Get_RegID(_T("	TSTAT_PRODUCTMODEL_SUBTSTATS	"))	;
		TSTAT_OVERRIDE_SUBTSTATS	=	Get_RegID(_T("	TSTAT_OVERRIDE_SUBTSTATS	"))	;
		TSTAT_SERIALNO_SUBTSTATS	=	Get_RegID(_T("	TSTAT_SERIALNO_SUBTSTATS	"))	;
		TSTAT_OFFTIME_SUBTSTATS	=	Get_RegID(_T("	TSTAT_OFFTIME_SUBTSTATS	"))	;
		TSTAT_ONTIME_SUBTSTATS	=	Get_RegID(_T("	TSTAT_ONTIME_SUBTSTATS	"))	;
		TEST50	=	Get_RegID(_T("	TEST50	"))	;
		VALUEINPUT1TO34	=	Get_RegID(_T("	VALUEINPUT1TO34	"))	;
		RANGE_INPUT1TO32	=	Get_RegID(_T("	RANGE_INPUT1TO32	"))	;
		FILTER_INPUT1TO32	=	Get_RegID(_T("	FILTER_INPUT1TO32	"))	;
		CALIBRATION_INPUT1TO32	=	Get_RegID(_T("	CALIBRATION_INPUT1TO32	"))	;
		TOTAL_TSTAT0	=	Get_RegID(_T("	TOTAL_TSTAT0	"))	;
		TOTAL_TSTAT1	=	Get_RegID(_T("	TOTAL_TSTAT1	"))	;
		TOTAL_TSTAT2	=	Get_RegID(_T("	TOTAL_TSTAT2	"))	;
		TSTAT_ADD_BOTH_CHANNEL_UART0	=	Get_RegID(_T("	TSTAT_ADD_BOTH_CHANNEL_UART0	"))	;
		TSTAT_ADD_BOTH_CHANNEL_UART1	=	Get_RegID(_T("	TSTAT_ADD_BOTH_CHANNEL_UART1	"))	;
		TSTAT_ADD_BOTH_CHANNEL_UART2	=	Get_RegID(_T("	TSTAT_ADD_BOTH_CHANNEL_UART2	"))	;


#endif




	}

 
// CDialgMiniPanel message handlers

void CDialgMiniPanel::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
#if 1

	//显示横标题
	m_msflexgridinput.put_TextMatrix(0,1,_T("Input Name"));
	m_msflexgridinput.put_TextMatrix(0,2,_T("Value"));
	//m_msflexgridinput.put_TextMatrix(0,3,_T("Auto/Manual"));
	m_msflexgridinput.put_TextMatrix(0,3,_T("Range"));
	m_msflexgridinput.put_TextMatrix(0,4,_T("Function"));


	//设置排/行数量
	m_msflexgridinput.put_Cols(5);
	m_msflexgridinput.put_Rows(33);//包括标题栏


	//设置列宽	
	m_msflexgridinput.put_ColWidth(0,400);
	m_msflexgridinput.put_ColWidth(3,1500);
	m_msflexgridinput.put_ColWidth(4,1000);
	//居中显示
	for (int col=0;col<5;col++)
	{ 
		m_msflexgridinput.put_ColAlignment(col,4);
	}

	//彩色显示
	for(int i=1;i<33;i++)		//排数量
	{

		for(int k=0;k<5;k++)	//列数量
		{
			if (i%2==1)
			{
				m_msflexgridinput.put_Row(i);m_msflexgridinput.put_Col(k);m_msflexgridinput.put_CellBackColor(RGB(255,255,255));
			}
			else
			{
				m_msflexgridinput.put_Row(i);m_msflexgridinput.put_Col(k);m_msflexgridinput.put_CellBackColor(COLOR_CELL);
			}
		}
	}




	//第3，4列11-26灰色显示
// 	for (int i=1;i<33;i++)
// 	{
// 
// 		m_msflexgridinput.put_TextMatrix(i,4,_T("°C"));	  
// 		m_msflexgridinput.put_Row(i);
// 		m_msflexgridinput.put_Col(4);
// 		m_msflexgridinput.put_CellBackColor(FLEXGRID_CELL_GRAY_COLOR);	   //灰色
// 	}


	//显示纵标题
	CString str;
	for(int i=1;i<33;i++)
	{

		str.Format(_T("%d"),i);

		m_msflexgridinput.put_TextMatrix(i,0,str);	 

// 		str = _T("Input ")+str;
// 		m_msflexgridinput.put_TextMatrix(i,1,str);
		m_msflexgridinput.put_TextMatrix(i,4,_T("Default"));	

	}

	//显示结果值
//	str =_T("");
//	for(int i=1;i<33;i++)
//	{

// 		str.Format(_T("%d"),i);
// 
// 		m_msflexgridinput.put_TextMatrix(i,0,str);
// 		str = _T("Input ")+str;
// 		m_msflexgridinput.put_TextMatrix(i,1,str);
// 
// 		//m_msflexgridinput.put_TextMatrix(i,3,_T("Auto"));
// 		m_msflexgridinput.put_TextMatrix(i,3,_T("On/Off"));
//		m_msflexgridinput.put_TextMatrix(i,4,_T("Default"));	


//	}


	//unsigned char writevalue[1];
	//writevalue[0] = 0;
	//int flg = Write_Multi(g_tstat_id,writevalue,144,10);
	//TRACE(_T("flg=%d\n"),flg);
	//ASSERT(flg>0);


	//============================================================================================================界面Output DO部份列表框
 
	//设置行/列数量
	m_msflexgridDO.put_Rows(13);
	m_msflexgridDO.put_Cols(6);
	//设置列宽	
	m_msflexgridDO.put_ColWidth(0,400);
	m_msflexgridDO.put_ColWidth(3,1500);

	//显示横标题
	m_msflexgridDO.put_TextMatrix(0,1,_T("Input Name"));
	m_msflexgridDO.put_TextMatrix(0,2,_T("Value"));
	m_msflexgridDO.put_TextMatrix(0,3,_T("Auto/Manual"));
	m_msflexgridDO.put_TextMatrix(0,4,_T("Range"));
	m_msflexgridDO.put_TextMatrix(0,5,_T("Function"));



	//居中显示
	for (int col=0;col<6;col++)
	{ 
		m_msflexgridDO.put_ColAlignment(col,4);
	}

	//彩色显示
	for(int i=1;i<13;i++)		//排数量
	{

		for(int k=0;k<6;k++)	//列数量
		{
			if (i%2==1)
			{
				m_msflexgridDO.put_Row(i);m_msflexgridDO.put_Col(k);m_msflexgridDO.put_CellBackColor(RGB(255,255,255));
			}
			else
			{
				m_msflexgridDO.put_Row(i);m_msflexgridDO.put_Col(k);m_msflexgridDO.put_CellBackColor(COLOR_CELL);
			}
		}
	}
	//显示纵标题
	CString str_output;
	for(int i=1;i<13;i++)
	{

		str_output.Format(_T("%d"),i);
		m_msflexgridDO.put_TextMatrix(i,0,str_output);	
// 		str_output = _T("Output ")+str_output;
// 		m_msflexgridDO.put_TextMatrix(i,1,str_output);
// 
// 		//m_msflexgrid_output.put_TextMatrix(i,3,_T("Off"));
// 		m_msflexgridDO.put_TextMatrix(i,4,_T("On/Off"));
 		m_msflexgridDO.put_TextMatrix(i,5,_T("Default"));
		m_msflexgridDO.put_Row(i);
		m_msflexgridDO.put_Col(4);
		m_msflexgridDO.put_CellBackColor(FLEXGRID_CELL_GRAY_COLOR);
	}



	//============================================================================================================界面Output AO部份列表框

	//设置行/列数量
	m_msflexgridAO.put_Rows(13);
	m_msflexgridAO.put_Cols(6);
	//设置列宽	
	m_msflexgridAO.put_ColWidth(0,400);
	m_msflexgridAO.put_ColWidth(3,1500);

	//显示横标题
	m_msflexgridAO.put_TextMatrix(0,1,_T("Input Name"));
	m_msflexgridAO.put_TextMatrix(0,2,_T("Value"));
	m_msflexgridAO.put_TextMatrix(0,3,_T("Auto/Manual"));
	m_msflexgridAO.put_TextMatrix(0,4,_T("Range"));
	m_msflexgridAO.put_TextMatrix(0,5,_T("Function"));



	//居中显示
	for (int col=0;col<6;col++)
	{ 
		m_msflexgridAO.put_ColAlignment(col,4);
	}

	//彩色显示
	for(int i=1;i<13;i++)		//排数量
	{

		for(int k=0;k<6;k++)	//列数量
		{
			if (i%2==1)
			{
				m_msflexgridAO.put_Row(i);m_msflexgridAO.put_Col(k);m_msflexgridAO.put_CellBackColor(RGB(255,255,255));
			}
			else
			{
				m_msflexgridAO.put_Row(i);m_msflexgridAO.put_Col(k);m_msflexgridAO.put_CellBackColor(COLOR_CELL);
			}
		}
	}
	//显示纵标题
	CString str_outputAO;
	for(int i=1;i<13;i++)
	{

		str_outputAO.Format(_T("%d"),i);
		m_msflexgridAO.put_TextMatrix(i,0,str_outputAO);	
// 		str_outputAO = _T("Output ")+str_outputAO;
// 		m_msflexgridAO.put_TextMatrix(i,1,str_outputAO);
// 
// 		//m_msflexgrid_output.put_TextMatrix(i,3,_T("Off"));
// 		m_msflexgridAO.put_TextMatrix(i,4,_T("On/Off"));
		m_msflexgridAO.put_TextMatrix(i,5,_T("Default"));
		m_msflexgridAO.put_Row(i);
		m_msflexgridAO.put_Col(4);
		m_msflexgridAO.put_CellBackColor(FLEXGRID_CELL_GRAY_COLOR);
	}

#endif 
	

}

void CDialgMiniPanel::Fresh()
{
	/*SetTimer(MiniPanelTimer,1000,NULL);
  	GetDatabase();*/


  	ShowMinipDialog();
}

void CDialgMiniPanel::ShowMinipDialog()
{

#if 1

	//============================================================System Parameters===============================================================

	m_CStrModel = _T("Mini Panel");
	//6	1	Modbus device address
	m_inaddress = _wtoi(vecminipanel.at(6).CStvalue);

	UINT nSelectSerialNumber = _wtoi(vecminipanel.at(0).CStvalue)+_wtoi(vecminipanel.at(1).CStvalue)*256+_wtoi(vecminipanel.at(2).CStvalue)*256*256+_wtoi(vecminipanel.at(3).CStvalue)*256*256*256;
	m_inSerialNum=nSelectSerialNumber;

	m_flFirmware = ((float)(_wtoi(vecminipanel.at(5).CStvalue)*256+_wtoi(vecminipanel.at(4).CStvalue)))/10;

	m_inHardware = _wtoi(vecminipanel.at(8).CStvalue);
	m_inBaudrate = _wtoi(vecminipanel.at(9).CStvalue);



	//==================================================Input============================================================
	//address: input 148~179
	//address:Switch 124~147
	CString strresult;

	for(int i = 1;i<=32;i++)
	{  
// 		strresult.Format(_T("%d°C"),10);
// 		m_msflexgridinput.put_TextMatrix(i,2,strresult);
// 		m_msflexgridinput.put_TextMatrix(i,1,_T("west door"));
// 		m_msflexgridinput.put_TextMatrix(i,3,_T("0-100%"));


		m_msflexgridinput.put_TextMatrix(i,2,vecminipanel.at(148-1+i).CStvalue);
		m_msflexgridinput.put_TextMatrix(i,1,vecminipanel.at(148-1+i).CStName);
		m_msflexgridinput.put_TextMatrix(i,3,vecminipanel.at(148-1+i).CStrange);
	}


	//====================================================Output============================================================	
	//100~111

	CString CstresultDO;
	for(int i = 1;i<=12;i++)
	{  
// 		CstresultDO.Format(_T("%d"),10);
// 		m_msflexgridDO.put_TextMatrix(i,2,CstresultDO);
// 		m_msflexgridDO.put_TextMatrix(i,1,_T("east door"));
// 		m_msflexgridDO.put_TextMatrix(i,3,_T("AUTO"));

		m_msflexgridDO.put_TextMatrix(i,2,vecminipanel.at(100-1+i).CStvalue);
		m_msflexgridDO.put_TextMatrix(i,1,vecminipanel.at(100-1+i).CStName);
		m_msflexgridDO.put_TextMatrix(i,3,vecminipanel.at(124-1+i).CStautomannel);
		m_msflexgridDO.put_TextMatrix(i,4,vecminipanel.at(100-1+i).CStrange);


	}




	//112~123
	CString CstresultAO;
	for(int i = 1;i<=12;i++)
	{  
// 		CstresultAO.Format(_T("%d"),10);
// 		ms_msflexgridAO.put_TextMatrix(i,2,CstresultAO);
// 		ms_msflexgridAO.put_TextMatrix(i,1,_T("south door"));
// 		ms_msflexgridAO.put_TextMatrix(i,3,_T("AUTO"));

		m_msflexgridAO.put_TextMatrix(i,2,vecminipanel.at(112-1+i).CStvalue);
		m_msflexgridAO.put_TextMatrix(i,1,vecminipanel.at(112-1+i).CStName);
		m_msflexgridAO.put_TextMatrix(i,3,vecminipanel.at(136-1+i).CStautomannel);
		m_msflexgridAO.put_TextMatrix(i,4,vecminipanel.at(112-1+i).CStrange);
	}

	UpdateData(FALSE);
#endif

	}

BOOL CDialgMiniPanel::GetDatabase()
{ 
	CADO m_ado;
	m_ado.OnInitADOConn();

	if(ifminidb)
	{

	//判断MiniPanel数据库是否存在,Auto/Manual text,Range text

	CString temptable = _T("MiniPanel");
	CString tempsql = _T("create table MiniPanel(Address Number Primary Key,Name text,Data text,AutoManual text,Range text)");//
		
	bool m_judge = m_ado.IsHaveTable(m_ado,temptable);

	//不存在 创建数据库表
	if (!m_judge) 
	{	
 		m_ado.m_pRecordset = m_ado.OpenRecordset(tempsql);
		//初始化表
		CString sql = _T("select * from MiniPanel");
		m_ado.m_pRecordset = m_ado.OpenRecordset(sql);
		if (m_ado.m_pRecordset->EndOfFile)
		{

		for(int i = 0;i<230;i++)
		{
			try 
			{
				m_ado.m_pRecordset->AddNew();
				m_ado.m_pRecordset->PutCollect("Address",(_bstr_t)(i+1));
				m_ado.m_pRecordset->PutCollect("Name",(_bstr_t)_T("Unused"));
				m_ado.m_pRecordset->PutCollect("Data",(_bstr_t)"On");
				m_ado.m_pRecordset->PutCollect("Range",(_bstr_t)_T("On/Off"));
				m_ado.m_pRecordset->PutCollect("AutoManual",(_bstr_t)"Auto");

				m_ado.m_pRecordset->Update();

			}


			catch(...)
			{

			}
		}
		}
		

	}

	ifminidb = FALSE;
	}

#if 1
	vecminipanel.clear();
 	CString SQL = _T("select * from MiniPanel"); 
 	m_ado.m_pRecordset = m_ado.OpenRecordset(SQL);
	_variant_t vartemp;
	while(!m_ado.m_pRecordset->EndOfFile)
	{
		MINImini.iaddress =m_ado.m_pRecordset->GetCollect(_T("Address"));
		vartemp =m_ado.m_pRecordset->GetCollect(_T("Name"));
		if (vartemp.vt==VT_NULL)
			MINImini.CStName =_T("");
		else
			MINImini.CStName =vartemp;


		vartemp =m_ado.m_pRecordset->GetCollect(_T("Data"));
		if (vartemp.vt==VT_NULL)
			MINImini.CStvalue =_T("");
		else
			MINImini.CStvalue =vartemp;


		vartemp =m_ado.m_pRecordset->GetCollect(_T("AutoManual"));
		if (vartemp.vt==VT_NULL)
			MINImini.CStautomannel =_T("");
		else
			MINImini.CStautomannel =vartemp;


		vartemp =m_ado.m_pRecordset->GetCollect(_T("Range"));
		if (vartemp.vt==VT_NULL)
			MINImini.CStrange =_T("");
		else
			MINImini.CStrange =vartemp;

		m_ado.m_pRecordset->MoveNext();

		vecminipanel.push_back(MINImini);
	}

//读取本电脑当前正在使用的串口。
	CString CSTcompot;
	BOOL BOdefault;
	SQL = _T("select * from Building");
	m_ado.m_pRecordset = m_ado.OpenRecordset(SQL);
	while(!m_ado.m_pRecordset->EndOfFile)
	{
		CSTcompot =(_variant_t)m_ado.m_pRecordset->GetCollect(_T("Com_Port"));
		BOdefault =(_variant_t)m_ado.m_pRecordset->GetCollect(_T("Default_SubBuilding"));//TRUE = -1即非0，FALSE就是0
		m_ado.m_pRecordset->MoveNext();

		if (BOdefault)
		{
			comnum = _wtoi(CSTcompot.Mid(3));
		}

	}



	m_ado.CloseRecordset();
	m_ado.CloseConn();





#endif 



	return TRUE;



}

BOOL CDialgMiniPanel::MiniUpdateData()
{
	KillTimer(MiniPanelTimer);
#if 1
	//读取串口号，从数据库
	//open_com(comnum);

	int sumret = 0;
	BOOL flag = FALSE;

	//读取miniPanel数据
	BOOL ret_bool = FALSE;
	long start = clock(),end(0); 		


	memset(&shmPRegister,0,sizeof(shmPRegister)); 
	for(int i=0;i<4;i++)
	{
		int ret = Read_Multi(g_tstat_id,&shmPRegister[i*64],i*64,64,2);
		sumret += ret;
		
		if (sumret<0)
		{
			TRACE(_T("write_multi ret sum = %d\n"),sumret);
			SetTimer(MiniPanelTimer,1000,NULL);
			return FALSE;
		}
			
	}



	for (int i = 0;i<230;i++)
	{
	//	vecminipanel.at(i).CStvalue = shmPRegister[i];		// error C2593: 'operator =' is ambiguous
		vecminipanel.at(i).CStvalue.Format(_T("%d"),shmPRegister[i]);	
		if (i>=124&&i<=147)
		{
			switch(shmPRegister[i])
			{
			case 0:
				vecminipanel.at(i).CStautomannel = _T("OFF");				
				break;
			case 1:
				vecminipanel.at(i).CStautomannel = _T("Manual");				
				break;
			case 2:
				vecminipanel.at(i).CStautomannel = _T("Auto");				
				break;
			default:
				break;
			}

		}

		if (i>=100&&i<=123)
		{

			if (shmPRegister[i]>512)
				vecminipanel.at(i).CStvalue = _T("ON"); 
			else
				vecminipanel.at(i).CStvalue = _T("OFF");

		}
	}

	if (sumret>200)
	{
		flag = TRUE;
	}
	TRACE(_T("write_multi ret sum = %d\n"),sumret);

	end = clock();
	long resultvalue = (end - start)/1000;
	TRACE(_T("GetData() usetime %d second\n"),resultvalue);

	
	SetTimer(MiniPanelTimer,1000,NULL);
#endif
	return flag;
}



void CDialgMiniPanel::OnTimer(UINT_PTR nIDEvent)
{

	CMainFrame* pMain = (CMainFrame*)AfxGetApp()->m_pMainWnd;
	CView* pNewView = pMain->m_pViews[6];
	CView* pActiveView = pMain->GetActiveView();

	if ( pNewView != pActiveView )    // current is minipanel dialog
	{
		KillTimer(MiniPanelTimer);
	}

#if 1
	static int nCount = 0,nCount2 = 0;

	nCount++;
	nCount2++;

	if (MiniPanelTimer == nIDEvent)
	{
		CTime now;
		now = CTime::GetCurrentTime();
		m_datetime = now.Format(_T("%A,%B %d,%Y  %H:%M:%S"));		// "Saturday, April 12, 2012"		

		UpdateData(FALSE);

		if (nCount% 30 == 0)
		{
	
			nCount = 0;

			BOOL flag = MiniUpdateData();

			if (flag)
			{
				ShowMinipDialog();
				SetPaneString(2,_T("Online!"));
				
			}

		}
		if (nCount2%120 == 0)
		{
			nCount2 = 0;
			Updatedatabase();

		}


	}

#endif
	CFormView::OnTimer(nIDEvent);
}

void CDialgMiniPanel::Updatedatabase()
{
	TRACE(_T("Updatedatabase()start!\n"));
	KillTimer(MiniPanelTimer);
	//存入数据库中
	CADO saveADO;
	saveADO.OnInitADOConn();
	CString sql = _T("select * from MiniPanel");
	saveADO.m_pRecordset = saveADO.OpenRecordset(sql);
	if (!saveADO.m_pRecordset->EndOfFile)
	{
		saveADO.m_pRecordset->MoveFirst();

	for(int i = 0;i<230;i++)
	{
		try 
		{

			//saveADO.m_pRecordset->AddNew();
			//saveADO.m_pRecordset->Move(pos,vtMissing);
			// 			cstnum.Format(_T("%d"),i+1);
			// 			saveADO.m_pRecordset->PutCollect("Address",(_bstr_t)cstnum);
			// 			saveADO.m_pRecordset->PutCollect("Name",(_bstr_t)_T("output"));

			saveADO.m_pRecordset->PutCollect("Address",(_bstr_t)i);
			saveADO.m_pRecordset->PutCollect("Name",(_bstr_t)vecminipanel.at(i).CStName);
			saveADO.m_pRecordset->PutCollect("Data",(_bstr_t)shmPRegister[i]);
			saveADO.m_pRecordset->PutCollect("Range",(_bstr_t)vecminipanel.at(i).CStrange);
			

			if (i>=124&&i<=147)
			{
				switch ((int)(_variant_t)shmPRegister[i])
				{
				case 0:   //0- off 1 - mannel 2 - auto
					saveADO.m_pRecordset->PutCollect("AutoManual",(_bstr_t)"OFF");
					break;
				case 1:
					saveADO.m_pRecordset->PutCollect("AutoManual",(_bstr_t)"Manual");
					break;
				case 2:
					saveADO.m_pRecordset->PutCollect("AutoManual",(_bstr_t)"Auto");
					break;
				default:
					break;

				}
			}


			//  		saveADO.m_pRecordset->PutCollect("Auto/Manual",(_bstr_t)"auto");
			//  		saveADO.m_pRecordset->PutCollect("Range",(_bstr_t)"10%-100%");
			saveADO.m_pRecordset->Update();
			saveADO.m_pRecordset->MoveNext();
		}


		catch(...)
		{
			//MessageBox(_T("Write dababase false!"));
			
			SetPaneString(2,_T("Write dababase false!"));
			return ;
		}
	}
	}
	else
	{
		for(int i = 0;i<230;i++)
		{
			try 
			{

				//saveADO.m_pRecordset->AddNew();
				//saveADO.m_pRecordset->Move(pos,vtMissing);
				// 			cstnum.Format(_T("%d"),i+1);
				// 			saveADO.m_pRecordset->PutCollect("Address",(_bstr_t)cstnum);
				// 			saveADO.m_pRecordset->PutCollect("Name",(_bstr_t)_T("output"));
				saveADO.m_pRecordset->AddNew();
				saveADO.m_pRecordset->PutCollect("Address",(_bstr_t)i);
				saveADO.m_pRecordset->PutCollect("Name",(_bstr_t)vecminipanel.at(i).CStName);
				saveADO.m_pRecordset->PutCollect("Data",(_bstr_t)shmPRegister[i]);
				saveADO.m_pRecordset->PutCollect("Range",(_bstr_t)vecminipanel.at(i).CStrange);


				if (i>=124&&i<=147)
				{
					switch ((int)(_variant_t)shmPRegister[i])
					{
					case 0:   //0- off 1 - mannel 2 - auto
						saveADO.m_pRecordset->PutCollect("AutoManual",(_bstr_t)"OFF");
						break;
					case 1:
						saveADO.m_pRecordset->PutCollect("AutoManual",(_bstr_t)"Manual");
						break;
					case 2:
						saveADO.m_pRecordset->PutCollect("AutoManual",(_bstr_t)"Auto");
						break;
					default:
						break;

					}
				}


				//  		saveADO.m_pRecordset->PutCollect("Auto/Manual",(_bstr_t)"auto");
				//  		saveADO.m_pRecordset->PutCollect("Range",(_bstr_t)"10%-100%");
				saveADO.m_pRecordset->Update();

			}


			catch(...)
			{
				//MessageBox(_T("Write dababase false!"));

				SetPaneString(2,_T("Write dababase false!"));
				return ;
			}
		}

	}

	saveADO.CloseRecordset();
	saveADO.CloseConn(); 

	SetTimer(MiniPanelTimer,1000,NULL);

}
void CDialgMiniPanel::OnEnKillfocusEditInput()
{

	CString strText;
	m_editinput.GetWindowText(strText); 
	m_editinput.ShowWindow(SW_HIDE);  
	int lRow = m_msflexgridinput.get_RowSel();	
	int lCol = m_msflexgridinput.get_ColSel(); 

	m_msflexgridinput.put_TextMatrix(lRow,lCol,strText);
	CString strrow;
	strrow.Format(_T("%d"),lRow);
	CString stremp;
	stremp = _T("CM5_INPUT");
	int passvalue = lRow+147;
	writedbinputname(passvalue,strText);

	CRect rcCell(0,0,1,1);
	m_editinput.MoveWindow(&rcCell,1);
	SetTimer(MiniPanelTimer,1000,NULL);
	TRACE(_T("KillfocusEditInput()end!\nSetTimer()start\n"));

}
BEGIN_EVENTSINK_MAP(CDialgMiniPanel, CFormView)
	ON_EVENT(CDialgMiniPanel, IDC_MSFLEXGRID_INPUT, DISPID_CLICK, CDialgMiniPanel::ClickMsflexgridInput, VTS_NONE)
	ON_EVENT(CDialgMiniPanel, IDC_MSFLEXGRID_OUTPUT_DO, DISPID_CLICK, CDialgMiniPanel::ClickMsflexgridOutputDo, VTS_NONE)
	ON_EVENT(CDialgMiniPanel, IDC_MSFLEXGRID_OUTPUT_AO, DISPID_CLICK, CDialgMiniPanel::ClickMsflexgridOutputAo, VTS_NONE)
END_EVENTSINK_MAP()

void CDialgMiniPanel::ClickMsflexgridInput()
{

	//使用edition控件形式显示

	long lRow,lCol;
	lRow = m_msflexgridinput.get_RowSel();
	lCol = m_msflexgridinput.get_ColSel(); 

	if(lCol == 1)
	{
		CRect rect;
		m_msflexgridinput.GetWindowRect(rect); //
		ScreenToClient(rect); //
		CDC* pDC =GetDC();

		int nTwipsPerDotX = 1440 / pDC->GetDeviceCaps(LOGPIXELSX) ;
		int nTwipsPerDotY = 1440 / pDC->GetDeviceCaps(LOGPIXELSY) ;

		long y = m_msflexgridinput.get_RowPos(lRow)/nTwipsPerDotY;
		long x = m_msflexgridinput.get_ColPos(lCol)/nTwipsPerDotX;

		long width = m_msflexgridinput.get_ColWidth(lCol)/nTwipsPerDotX+1;
		long height = m_msflexgridinput.get_RowHeight(lRow)/nTwipsPerDotY+1;

		CRect rcCell(x,y,x+width,y+height);

		rcCell.OffsetRect(rect.left+1,rect.top+1);
		ReleaseDC(pDC);
		CString strValue = m_msflexgridinput.get_TextMatrix(lRow,lCol);

		if(1==lCol)		
		{	
			KillTimer(MiniPanelTimer);
			TRACE(_T("ClickMsflexgridInput()start!\nKillTimer()start\n"));
			m_editinput.MoveWindow(&rcCell,1);
			m_editinput.ShowWindow(SW_SHOW);	
			m_editinput.SetWindowText(strValue);	
			m_editinput.SetFocus();
			m_editinput.SetCapture();//使随后的鼠标输入都被发送到这个CWnd 
			int nLenth=strValue.GetLength();	
			m_editinput.SetSel(nLenth,nLenth); 

		}	

	}


}

void CDialgMiniPanel::OnEnKillfocusEditoutputdo()
{
	CString strText;
	m_editoutputdo.GetWindowText(strText); 
	m_editoutputdo.ShowWindow(SW_HIDE);  
	int lRow = m_msflexgridDO.get_RowSel();	
	int lCol = m_msflexgridDO.get_ColSel(); 

	m_msflexgridDO.put_TextMatrix(lRow,lCol,strText);
	CString strrow;
	strrow.Format(_T("%d"),lRow);
	CString stremp;
	stremp = _T("CM5_INPUT");
	int passvalue = lRow+99;
	writedbinputname(passvalue,strText);

	CRect rcCell(0,0,1,1);
	m_editoutputdo.MoveWindow(&rcCell,1);
	SetTimer(MiniPanelTimer,1000,NULL);
}

void CDialgMiniPanel::OnEnKillfocusEditOutputao()
{

	CString strText;
	m_editoutputao.GetWindowText(strText); 
	m_editoutputao.ShowWindow(SW_HIDE);  
	int lRow = m_msflexgridAO.get_RowSel();	
	int lCol = m_msflexgridAO.get_ColSel(); 

	m_msflexgridAO.put_TextMatrix(lRow,lCol,strText);
	CString strrow;
	strrow.Format(_T("%d"),lRow);
	CString stremp;
	stremp = _T("CM5_INPUT");
	int passvalue = lRow+111;
	writedbinputname(passvalue,strText);

	CRect rcCell(0,0,1,1);
	m_editoutputao.MoveWindow(&rcCell,1);
	SetTimer(MiniPanelTimer,1000,NULL);
}

void CDialgMiniPanel::ClickMsflexgridOutputDo()
{

	//使用edition控件形式显示

	long lRow,lCol;
	lRow = m_msflexgridDO.get_RowSel();
	lCol = m_msflexgridDO.get_ColSel(); 

	if(lCol == 1)
	{
		CRect rect;
		m_msflexgridDO.GetWindowRect(rect); //
		ScreenToClient(rect); //
		CDC* pDC =GetDC();

		int nTwipsPerDotX = 1440 / pDC->GetDeviceCaps(LOGPIXELSX) ;
		int nTwipsPerDotY = 1440 / pDC->GetDeviceCaps(LOGPIXELSY) ;

		long y = m_msflexgridDO.get_RowPos(lRow)/nTwipsPerDotY;
		long x = m_msflexgridDO.get_ColPos(lCol)/nTwipsPerDotX;

		long width = m_msflexgridDO.get_ColWidth(lCol)/nTwipsPerDotX+1;
		long height = m_msflexgridDO.get_RowHeight(lRow)/nTwipsPerDotY+1;

		CRect rcCell(x,y,x+width,y+height);

		rcCell.OffsetRect(rect.left+1,rect.top+1);
		ReleaseDC(pDC);
		CString strValue = m_msflexgridDO.get_TextMatrix(lRow,lCol);

		if(1==lCol)		
		{
			KillTimer(MiniPanelTimer);
			TRACE(_T("ClickMsflexgridInput()start!\nKillTimer()start\n"));
			m_editoutputdo.MoveWindow(&rcCell,1);
			m_editoutputdo.ShowWindow(SW_SHOW);	
			m_editoutputdo.SetWindowText(strValue);	
			m_editoutputdo.SetFocus();
			m_editoutputdo.SetCapture();//使随后的鼠标输入都被发送到这个CWnd 
			int nLenth=strValue.GetLength();	
			m_editoutputdo.SetSel(nLenth,nLenth); 

		}	

	}

}

void CDialgMiniPanel::ClickMsflexgridOutputAo()
{

	//使用edition控件形式显示

	long lRow,lCol;
	lRow = m_msflexgridAO.get_RowSel();
	lCol = m_msflexgridAO.get_ColSel(); 

	if(lCol == 1)
	{
		CRect rect;
		m_msflexgridAO.GetWindowRect(rect); //
		ScreenToClient(rect); //
		CDC* pDC =GetDC();

		int nTwipsPerDotX = 1440 / pDC->GetDeviceCaps(LOGPIXELSX) ;
		int nTwipsPerDotY = 1440 / pDC->GetDeviceCaps(LOGPIXELSY) ;

		long y = m_msflexgridAO.get_RowPos(lRow)/nTwipsPerDotY;
		long x = m_msflexgridAO.get_ColPos(lCol)/nTwipsPerDotX;

		long width = m_msflexgridAO.get_ColWidth(lCol)/nTwipsPerDotX+1;
		long height = m_msflexgridAO.get_RowHeight(lRow)/nTwipsPerDotY+1;

		CRect rcCell(x,y,x+width,y+height);

		rcCell.OffsetRect(rect.left+1,rect.top+1);
		ReleaseDC(pDC);
		CString strValue = m_msflexgridAO.get_TextMatrix(lRow,lCol);

		if(1==lCol)		
		{	
			KillTimer(MiniPanelTimer);
			TRACE(_T("ClickMsflexgridInput()start!\nKillTimer()start\n"));
			m_editoutputao.MoveWindow(&rcCell,1);
			m_editoutputao.ShowWindow(SW_SHOW);	
			m_editoutputao.SetWindowText(strValue);	
			m_editoutputao.SetFocus();
			m_editoutputao.SetCapture();//使随后的鼠标输入都被发送到这个CWnd 
			int nLenth=strValue.GetLength();	
			m_editoutputao.SetSel(nLenth,nLenth); 

		}	

	}

}

void CDialgMiniPanel::writedbinputname( int& num,CString& str )
{


	//存入数据库中
	CADO saveADO;
	saveADO.OnInitADOConn();
	CString sql = _T("select * from MiniPanel");
	saveADO.m_pRecordset = saveADO.OpenRecordset(sql);
	CString cstnum;
		try 
		{
			saveADO.m_pRecordset->Move(num,vtMissing);
			saveADO.m_pRecordset->PutCollect("Name",(_bstr_t)str);
			saveADO.m_pRecordset->Update();

		}
		catch(...)
		{
			SetPaneString(2,_T("'Input Name' Write dababase false!"));
			return ;
		}


	vecminipanel.at(num).CStName = str;
	saveADO.CloseRecordset();
	saveADO.CloseConn(); 


}