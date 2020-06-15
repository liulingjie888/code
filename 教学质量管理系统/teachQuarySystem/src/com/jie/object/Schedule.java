package com.jie.object;

public class Schedule {
    private String sch_id="0";
    private String sch_name="";
    private String sch_term="";
    private String tea_name="";
    private String cla_name="";
    private String sch_remark="";
    private String avg_code="0";

    public void setSch_id(String sch_id){this.sch_id=sch_id;}
    public String getSch_id(){return sch_id;}

    public void setSch_name(String sch_name){this.sch_name = sch_name;}
    public String getSch_name(){return sch_name;}

    public void setSch_term(String sch_term){this.sch_term=sch_term;}
    public String getSch_term(){return sch_term;}

    public void setTea_name(String tea_name){this.tea_name=tea_name;}
    public String getTea_name(){return tea_name;}

    public void setCla_name(String cla_name){this.cla_name=cla_name;}
    public String getCla_name(){return cla_name;}

    public void setSch_remark(String sch_remark){this.sch_remark=sch_remark;}
    public String getSch_remark(){return sch_remark;}

    public void setAvg_code(String avg_code){this.avg_code=avg_code;}
    public String getAvg_code(){return avg_code;}

}
