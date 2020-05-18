VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   2640
   ClientLeft      =   120
   ClientTop       =   465
   ClientWidth     =   3930
   LinkTopic       =   "Form1"
   ScaleHeight     =   2640
   ScaleWidth      =   3930
   StartUpPosition =   3  '窗口缺省
   Begin VB.CommandButton Command2 
      Caption         =   "结束"
      Height          =   375
      Left            =   2880
      TabIndex        =   6
      Top             =   1920
      Width           =   735
   End
   Begin VB.CommandButton Command1 
      Caption         =   "清除"
      Height          =   375
      Left            =   2880
      TabIndex        =   5
      Top             =   1080
      Width           =   735
   End
   Begin VB.PictureBox Picture1 
      Height          =   1335
      Left            =   240
      ScaleHeight     =   1275
      ScaleWidth      =   2235
      TabIndex        =   4
      Top             =   960
      Width           =   2295
   End
   Begin VB.TextBox Text2 
      Height          =   375
      Left            =   2880
      TabIndex        =   3
      Text            =   "Text1"
      Top             =   360
      Width           =   735
   End
   Begin VB.TextBox Text1 
      Height          =   375
      Left            =   1080
      TabIndex        =   2
      Text            =   "Text1"
      Top             =   360
      Width           =   735
   End
   Begin VB.Label Label2 
      Caption         =   "输入订票张数"
      Height          =   375
      Left            =   2040
      TabIndex        =   1
      Top             =   360
      Width           =   615
   End
   Begin VB.Label Label1 
      Caption         =   "输入订票月份"
      Height          =   375
      Left            =   240
      TabIndex        =   0
      Top             =   360
      Width           =   615
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Dim month As Byte
Dim num%
Dim price As Currency

Private Sub Command1_Click()
Text1.Text = ""
Text2.Text = ""
Picture1.Cls
End Sub

Private Sub Command2_Click()
End
End Sub

Private Sub Form_Load()
Text1.Text = ""
Text2.Text = ""
Text1.MaxLength = 2
Text2.MaxLength = 5
End Sub

Private Sub Text1_Change()

flag = Text1.SelStart

If Val(Left(Text1.Text, 1)) > 1 Then
    Text1.Text = Left(Text1.Text, 1)
    Text1.SelStart = flag
Else
    If Val(Text1.Text) > 12 Then
        Text1.Text = Left(Text1.Text, 1)
        Text1.SelStart = flag
    End If
End If
End Sub

Private Sub Text1_KeyPress(KeyAscii As Integer)
If KeyAscii = 13 Then
month = Val(Text1.Text)
num = Val(Text2.Text)

If month >= 7 And month <= 9 Then

If num <= 20 Then
price = num * 95
Else
price = num * 85
End If

ElseIf (month >= 1 And month <= 5) Or month = 10 Or month = 11 Then

If num <= 20 Then
price = num * 80
Else
price = num * 70
End If

Else
price = num * 98
End If
End If
Picture1.Cls
Picture1.Print vbCrLf & "原票价  " & num * 100 & vbCrLf
Picture1.Print "优惠价  " & price & vbCrLf
Picture1.Print "优惠价  " & num * 100 - price
End Sub

Private Sub Text2_Change()
If Left(Text2.Text, 1) = "-" Then Text2.Text = ""
End Sub

Private Sub Text2_KeyPress(KeyAscii As Integer)
If KeyAscii = 13 Then
month = Val(Text1.Text)
num = Val(Text2.Text)

If month >= 7 And month <= 9 Then

If num <= 20 Then
price = num * 95
Else
price = num * 85
End If

ElseIf (month >= 1 And month <= 5) Or month = 10 Or month = 11 Then

If num <= 20 Then
price = num * 80
Else
price = num * 70
End If

Else
price = num * 98
End If
End If
Picture1.Cls
Picture1.Print vbCrLf & "原票价  " & num * 100 & vbCrLf
Picture1.Print "优惠价  " & price & vbCrLf
Picture1.Print "优惠价  " & num * 100 - price
End Sub
