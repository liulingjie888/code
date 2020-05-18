VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   1905
   ClientLeft      =   120
   ClientTop       =   465
   ClientWidth     =   4560
   LinkTopic       =   "Form1"
   ScaleHeight     =   1905
   ScaleWidth      =   4560
   StartUpPosition =   3  '窗口缺省
   Begin VB.TextBox Text1 
      Height          =   495
      Left            =   240
      TabIndex        =   0
      Text            =   "Text1"
      Top             =   600
      Width           =   1935
   End
   Begin VB.Label Label3 
      Alignment       =   2  'Center
      Caption         =   "Label3"
      Height          =   735
      Left            =   2640
      TabIndex        =   3
      Top             =   480
      Width           =   1455
   End
   Begin VB.Label Label2 
      Caption         =   "各位数值和为"
      Height          =   255
      Left            =   2760
      TabIndex        =   2
      Top             =   240
      Width           =   1215
   End
   Begin VB.Label Label1 
      Caption         =   "请输入一个不超过5位的数"
      Height          =   375
      Left            =   240
      TabIndex        =   1
      Top             =   240
      Width           =   2175
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Dim sum%
Dim a As String

Private Sub Form_Load()
Label3.FontSize = 40
Text1.FontSize = 20
Label3.Caption = ""
Text1.Text = ""
Text1.MaxLength = 5
End Sub

Private Sub Text1_Change()
sum = 0

flag = Text1.SelStart

For i = 0 To Len(Text1.Text) - 1
Text1.SelStart = i
Text1.SelLength = 1
sum = sum + Val(Text1.SelText)
Next i

Text1.SelStart = flag
Label3.Caption = sum
End Sub
