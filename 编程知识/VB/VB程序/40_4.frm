VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   2520
   ClientLeft      =   120
   ClientTop       =   465
   ClientWidth     =   3180
   LinkTopic       =   "Form1"
   ScaleHeight     =   2520
   ScaleWidth      =   3180
   StartUpPosition =   3  '窗口缺省
   Begin VB.TextBox Text4 
      Height          =   375
      Left            =   2160
      TabIndex        =   7
      Text            =   "Text3"
      Top             =   1680
      Width           =   855
   End
   Begin VB.TextBox Text3 
      Height          =   375
      Left            =   960
      TabIndex        =   6
      Text            =   "Text3"
      Top             =   1680
      Width           =   615
   End
   Begin VB.TextBox Text2 
      Height          =   375
      Left            =   1440
      TabIndex        =   3
      Text            =   "Text1"
      Top             =   1080
      Width           =   1215
   End
   Begin VB.TextBox Text1 
      Height          =   375
      Left            =   1440
      TabIndex        =   2
      Text            =   "Text1"
      Top             =   480
      Width           =   1215
   End
   Begin VB.Label Label4 
      Caption         =   "通话费用"
      Height          =   375
      Left            =   1680
      TabIndex        =   5
      Top             =   1680
      Width           =   375
   End
   Begin VB.Label Label3 
      Caption         =   "通话时间"
      Height          =   375
      Left            =   480
      TabIndex        =   4
      Top             =   1680
      Width           =   375
   End
   Begin VB.Label Label2 
      Caption         =   "结束通话hh:mm:ss"
      Height          =   375
      Left            =   480
      TabIndex        =   1
      Top             =   1080
      Width           =   735
   End
   Begin VB.Label Label1 
      Caption         =   "开始通话hh:mm:ss"
      Height          =   375
      Left            =   480
      TabIndex        =   0
      Top             =   480
      Width           =   735
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Dim dt As Integer
Dim dt1, dt2 As Date
Dim price As Currency


Private Sub Form_Load()
Text1.Text = ""
Text2.Text = ""
Text3.Text = ""
Text4.Text = ""
End Sub

Private Sub Text2_KeyPress(KeyAscii As Integer)
If KeyAscii = 13 Then
dt1 = CDate(Text1.Text)
dt2 = CDate(Text2.Text)

dt = DateDiff("n", dt1, dt2)

If dt1 > CDate("07:00:00") And dt2 < CDate("19:00:00") Then
If dt <= 3 Then
price = dt * 0.5
Else
price = 1.5 + (dt - 3) * 0.15
End If
Else
If dt <= 3 Then
price = dt * 0.25
Else
price = 0.75 + (dt - 3) * 0.075
End If
End If
End If
Text3.Text = dt & "分"
Text4.Text = Format(price, "0.00") & "元"
End Sub

