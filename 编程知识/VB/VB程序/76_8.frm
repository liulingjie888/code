VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   2400
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   4680
   LinkTopic       =   "Form1"
   ScaleHeight     =   2400
   ScaleWidth      =   4680
   StartUpPosition =   3  '窗口缺省
   Begin VB.CommandButton Command2 
      Caption         =   "清除"
      Height          =   375
      Left            =   3600
      TabIndex        =   4
      Top             =   1920
      Width           =   615
   End
   Begin VB.CommandButton Command1 
      Caption         =   "压缩"
      Height          =   375
      Left            =   720
      TabIndex        =   3
      Top             =   1920
      Width           =   615
   End
   Begin VB.PictureBox Picture1 
      Height          =   495
      Left            =   720
      ScaleHeight     =   435
      ScaleWidth      =   3435
      TabIndex        =   2
      Top             =   1200
      Width           =   3495
   End
   Begin VB.TextBox Text1 
      Height          =   495
      Left            =   720
      TabIndex        =   0
      Text            =   "Text1"
      Top             =   480
      Width           =   3495
   End
   Begin VB.Label Label2 
      Alignment       =   2  'Center
      Caption         =   "请输入一个二进制字符串"
      Height          =   495
      Left            =   720
      TabIndex        =   1
      Top             =   120
      Width           =   2775
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Dim text As String

Private Sub Command1_Click()
Picture1.Cls
a = shrink()
Picture1.Print text
End Sub

Private Sub Command2_Click()
Text1.text = ""
text = ""
Text1.SetFocus
Picture1.Cls
End Sub

Private Sub Form_Load()
Text1.text = ""
End Sub

Public Function shrink()
Dim str, str1, str2 As String
Dim i%
Dim num%
If Text1.text = "" Then Text1.SetFocus: Exit Function
str = Text1.text & "*"
num = 0
text = ""
For i = 1 To Len(str) - 1
    str1 = Mid(str, i, 1)
    str2 = Mid(str, i + 1, 1)
    If (str1 = "0" And str2 = "0") Or (str1 = "1" And str2 = "1") Then
        num = num + 1
    Else
        num = num + 1
        text = text & num & "*"
        num = 0
    End If
Next i
   text = Left(text, Len(text) - 1)
End Function


Private Sub Text1_KeyPress(KeyAscii As Integer)
If Not (KeyAscii = 48 Or KeyAscii = 49 Or KeyAscii = 8) Then
   KeyAscii = 0
   
End If
End Sub

