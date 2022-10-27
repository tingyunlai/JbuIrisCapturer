#define JBU_FALSE  0
#define JBU_OK     1
#define JBU_INVALID_MARKER 2
#define JBU_FAIL_OPEN      3
const LONG		ONE_MSEC = 10000;   // The number of 100-ns in 1 msec
const UINT		TICK_FREQ = 200;	// Timer frequency in msec	


//Flags to show which notification messages to display
#define FLAG_NONE_MSG            0x00000000
#define FLAG_MOUSE_MSG           0x00000001
#define FLAG_KEY_MSG             0x00000002
#define FLAG_SIZE_MSG            0x00000004
#define FLAG_DRAGDROP_MSG        0x00000008
#define FLAG_ZOOM_MSG            0x00000010
#define FLAG_SCALE_MSG           0x00000020
#define FLAG_FOCUS_MSG           0x00000040
#define FLAG_SCROLL_MSG          0x00000080
#define FLAG_PAINT_MSG           0x00000100
#define FLAG_VECTORCHANGED_MSG   0x00000200
#define FLAG_ALL_MSG             0x000003FF


// the structure is aimed to manipulate layer information
//PCB
typedef struct _JBULAYERINFO
{
	CString		szTypeName;
	CString		szName;
	long		nOrder;
	COLORREF	nColor;
	COLORREF	nFlash;
	BOOL		bVisible;
	BOOL		bSelectable;
	BOOL		bTrueWidth;
	BOOL		bOutline;
	BOOL		bUsed;
}JbuLayerInfo, *pJbuLayerInfo;

enum JBU_ENUM_FUNCTION
{
	JBU_ENUM_NONE,
	JBU_ENUM_ALL_OBJECT,
	JBU_ENUM_SELECTED_OBJECT,
	JBU_SHOW_ALL_OBJECT,
	JBU_SHOW_SELECTED_OBJECT,

};

enum JBU_WINDOW_FUNCTION
{
	JBU_HOME_WINDOW,
	JBU_CAPTURE_WINDOW,
	JBU_ENCODED_WINDOW,
	JBU_PLAYBACK_WINDOW
};
//PCB end
enum PlaybackState
{
	STATE_RUNNING,
	STATE_PAUSED,
	STATE_STOPPED,
	STATE_CLOSED
};

enum JbuTemplateID
{
	Jbu_Template_Blink,
	Jbu_Template_NoToolbar,
	Jbu_Template_Toolbar1, //打点
	Jbu_Template_Toolbar2,
	Jbu_Template_Toolbar3,  //资料馆
	Jbu_Template_SliderOnly
};  

enum JbuCaptureDevice
{
	JBU_DEVICE_DECKLINK,
	JBU_DEVICE_DV
};

enum {
	JBU_IMAGE_VIEW_FIT_WINDOW,
	JBU_IMAGE_VIEW_FIT_HEIGHT,
	JBU_IMAGE_VIEW_FIT_WIDTH,
	JBU_IMAGE_VIEW_NORMAL,
	JBU_IMAGE_VIEW_ZOOM_IN,
	JBU_IMAGE_VIEW_ZOOM_OUT,
	JBU_IMAGE_VIEW_ZOOM_RECT

};

enum {
	JBU_FACE_EXPRESSION_ANGRY,
	JBU_FACE_EXPRESSION_SADNESS,
	JBU_FACE_EXPRESSION_SURPRISE,
	JBU_FACE_EXPRESSION_DISGUST,
	JBU_FACE_EXPRESSION_SMILE,
	JBU_FACE_EXPRESSION_FEAR,
	JBU_FACE_EXPRESSION_UNKNOWN

};

typedef struct _BANK_CARD_INFO
{
	char fullid[100];
	long storeid;
	long id;
	char name[255];
	char address[255];
	char tel[255];
	char cardno[255];
	char cardpass[255];
	char personid[255];
	int  score;
	char eyePos[32];
}BankCardInfo, *pBankCardInfo;
