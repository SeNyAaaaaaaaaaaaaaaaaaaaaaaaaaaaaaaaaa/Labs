package com.warehouse;

public class Addressing {
    private int row;
    private int cell;
    private String storageArea;

    public Addressing() {
        this.row = 0;
        this.cell = 0;
        this.storageArea = "";
    }
    
    public Addressing(int row, int cell, String storageArea) {
        this.row = row;
        this.cell = cell;
        this.storageArea = storageArea;
    }
    
    public String getAddress() {
        return "Ряд " + row + ", Ячейка " + cell;
    }
    
    public String getFullAddress() {
        return "Зона: " + storageArea + ", " + getAddress();
    }
    
    public void displayAddress() {
        System.out.println(getFullAddress());
    }
    
    public int getRow() { 
        return row; 
    }
    public int getCell() { 
        return cell; 
    }
    public String getStorageArea() {
         return storageArea; 
    }
    
    public void setRow(int row) {
         this.row = row; 
    }

    public void setCell(int cell) {
         this.cell = cell; 
    }

    public void setStorageArea(String storageArea) {
         this.storageArea = storageArea;
    }
}