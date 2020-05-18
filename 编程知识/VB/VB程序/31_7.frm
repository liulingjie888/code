VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   2445
   ClientLeft      =   120
   ClientTop       =   465
   ClientWidth     =   4560
   LinkTopic       =   "Form1"
   ScaleHeight     =   2445
   ScaleWidth      =   4560
   StartUpPosition =   3  '窗口缺省
   Begin VB.TextBox Text2 
      Height          =   375
      Left            =   2040
      TabIndex        =   4
      Text            =   "Text2"
      Top             =   1080
      Width           =   1815
   End
   Begin VB.TextBox Text1 
      Height          =   375
      Left            =   2040
      TabIndex        =   3
      Text            =   "Text1"
      Top             =   360
      Width           =   1815
   End
   Begin VB.Label Label4 
      BorderStyle     =   1  'Fixed Single
      Caption         =   "Label4"
      Height          =   375
      Left            =   2040
      TabIndex        =   5
      Top             =   1680
      Width           =   1815
   End
   Begin VB.Label Label3 
      Caption         =   "本月实得工资（元）"
      Height          =   255
      Left            =   240
      TabIndex        =   2
      Top             =   1680
      Width           =   1695
   End
   Begin VB.Label Label2 
      Caption         =   "输入月工作天数"
      Height          =   255
      Left            =   480
      TabIndex        =   1
      Top             =   1080
      Width           =   1335
   End
   Begin VB.Label Label1 
      Caption         =   "输入日工资"
      Height          =   255
      Left            =   840
      TabIndex        =   0
      Top             =   480
      Width           =   975
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Dim P, AP, AP1 As Currency
Dim D%

Private Sub Form_Load()
Text1.Text = ""
Text2.Text = ""
Label4.Caption = ""
Text1.MaxLength = 6
Text2.MaxLength = 2
End Sub

Private Sub Text1_Change()
If Left(Text1.Text, 1) = "-" Then Text1.Text = Right(Text1.Text, Len(Text1.Text) - 1)

If Text2.Text = "" Or Text1.Text = "" Then
Label4.Caption = ""
Else
    D = Val(Text2.Text)
    P = Val(Text1.Text)
    AP1 = D * P
    AP = AP1 * 0.945 - 27.83
    If AP >= 0 Then
        Label4.Caption = Format(AP, ".00")
    Else
        Label4.Caption = 0
    End If
End If
End Sub

Private Sub Text2_Change()

If Left(Text2.Text, 1) = "-" Then Text2.Text = Right(Text2.Text, Len(Text2.Text) - 1)

flag = Text2.SelStart
If Val(Left(Text2.Text, 1)) > 3 Then
Text2.Text = Left(Text2.Text, 1)
Else
    If Val(Text2.Text) > 31 Then Text2.Text = Left(Text2.Text, 1)
End If
Text2.SelStart = flag

D = Val(Text2.Text)
If Text2.Text = "" Or Text1.Text = "" Then
    Label4.Caption = ""
Else
    P = Val(Text1.Text)
    AP1 = D * P
    AP = AP1 * 0.945 - 27.83
    If AP >= 0 Then
        Label4.Caption = Format(AP, ".00")
    Else
        Label4.Caption = 0
        End If
End If
End Sub
