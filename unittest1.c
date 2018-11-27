/************************************************************************************
 * Filename: Unittest1.c
 * Author : Steve and Swarupa
 *
 * Description : This file tests each and every functionality used individually using CUnits
 *
 * *********************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include "inc/common_variable.h"
#include "CUnit/Basic.h"
#include "inc/main.h"

#define COUNT (10)
uint8_t *p;
uint8_t data_pop;
uint8_t parameter_value[COUNT];
CB buffer_1;
CB buffer_2;
CB buffer_3;
CB buffer_4;
CB buffer_5;
CB buffer_6;
CB buffer_7;
CB buffer_8;

/*a random value generator function */
int random_generator(int8_t seed)
{

   
 
  for(int i= 0; i<COUNT; i++) 
    {
     seed = (7 *seed) % 8191;
     if(seed > 200)
     {
      seed = seed % 200;
     }
     parameter_value[i] = seed;
    }
    return 0;

}  

int init(void)
{
	init_CB(&buffer_2, (COUNT/2));
	init_CB(&buffer_3, (COUNT));
	//return 0;

}

int init_delete(void)
{
	init_CB(&buffer_4, (COUNT));
	//return 0;
}


/*initiating suite*/
int init_suite_init_CB(void)
{
	return 0;
}


int init_suite_report_data(void)
{
    init_CB(&buffer_5, (COUNT));
	return 0;
}

int init_suite_resize(void)
{
    init_CB(&buffer_6, (COUNT/2));
    init_CB(&buffer_7, (COUNT));
     int i;
        
	for(p= parameter_value,i=0; i<COUNT/2 ; i++, p++)
	{
		insert_data(&buffer_6,*p);
	}
	return 0;
}

int init_suite_clear(void)
{
    init_CB(&buffer_8, (COUNT));
     int i;
        
	for(p= parameter_value,i=0; i<COUNT ; i++, p++)
	{
		insert_data(&buffer_8,*p);
	}
	return 0;
}

/*Cleaning suite*/
int clean_suite(void)
{
	return 0;
}

/*Adding test registry*/
void test_init_CB() //suite1
{
        int i;
        
	for(p= parameter_value,i=0; i<COUNT ; i++, p++)
	{
		CU_ASSERT_EQUAL(insert_data(&buffer_1,*p),BUFFER_NOT_INITIALISED);
	}
      
    for(p= parameter_value,i=0; i<COUNT ; i++, p++)
	{
		CU_ASSERT_EQUAL(delete_CB(&buffer_1),BUFFER_NOT_INITIALISED);
	} 

	for(p= parameter_value,i=0; i<COUNT ; i++, p++)
	{
		CU_ASSERT_EQUAL(report_data(&buffer_1),BUFFER_NOT_INITIALISED);
	}

	for(p= parameter_value,i=0; i<COUNT ; i++, p++)
	{
		CU_ASSERT_EQUAL(clear_buffer(&buffer_1),BUFFER_NOT_INITIALISED);
	}

	for(p= parameter_value,i=0; i<COUNT ; i++, p++)
	{
		CU_ASSERT_EQUAL(resize_CB(&buffer_1,*p),BUFFER_NOT_INITIALISED);
	}

	for(p= parameter_value,i=0; i<COUNT ; i++, p++)
	{
		CU_ASSERT_EQUAL(init_CB(&buffer_1,*p),SUCCESS);
	}
        
	CU_ASSERT_EQUAL(init_CB(&buffer_1, -1), ERROR);
	CU_ASSERT_EQUAL(init_CB(&buffer_1, 0), ERROR);


}

void test_insert_data() //suite2
{
	int i;
    for(p= parameter_value,i=0; i<(COUNT) ; i++, p++)
	{
		if(i < (COUNT)/2)
		{
			CU_ASSERT_EQUAL(insert_data(&buffer_2,*p),SUCCESS);

		}
		else
		{

			CU_ASSERT_EQUAL(insert_data(&buffer_2,*p),-4);
		}
	}
	
	CU_ASSERT_EQUAL(insert_data(&buffer_3, '0'),SUCCESS);
	CU_ASSERT_EQUAL(insert_data(&buffer_3, '&'),SUCCESS);
	CU_ASSERT_EQUAL(insert_data(&buffer_3, ','),SUCCESS);
	CU_ASSERT_EQUAL(insert_data(&buffer_3, '\n'),SUCCESS);
	CU_ASSERT_EQUAL(insert_data(&buffer_3, ' '),SUCCESS);
	CU_ASSERT_EQUAL(insert_data(&buffer_3, 'z'),SUCCESS);
	CU_ASSERT_EQUAL(insert_data(&buffer_3, '\\'),SUCCESS); 
	CU_ASSERT_EQUAL(insert_data(&buffer_3, 5),SUCCESS); 
	CU_ASSERT_EQUAL(insert_data(&buffer_3, 0),SUCCESS);      
    

	CU_ASSERT_EQUAL(insert_data(&buffer_3, 0),SUCCESS);  

	CU_ASSERT_EQUAL(delete_CB(&buffer_2), SUCCESS);
	CU_ASSERT_EQUAL(delete_CB(&buffer_3), SUCCESS);

  
   
}

void test_delete_data() //suite3
{

	int i;
	for(i=0; i<COUNT ; i++)
	{
		if(i == 0)
		{
			CU_ASSERT_EQUAL(delete_CB(&buffer_4),SUCCESS);
		}
		else
		{
			CU_ASSERT_EQUAL(delete_CB(&buffer_4),BUFFER_NOT_INITIALISED);
		}
	}

}

void test_pop_and_report_data() //suite4
{
	int i;
  	for(p= parameter_value,i=0; i<(COUNT/2) ; i++, p++)
	{
		CU_ASSERT_EQUAL(insert_data(&buffer_5,*p),SUCCESS);
	}

	for(i=0; i<(COUNT/2) ; i++)
	{
		
		CU_ASSERT_EQUAL(report_data(&buffer_5),SUCCESS);
	}

	for(i=0; i<(COUNT/2) ; i++)
	{
		
			CU_ASSERT_EQUAL(pop_data(&buffer_5, &data_pop),SUCCESS);
	}

	for(i=0; i<(COUNT/2) ; i++)
	{
		
		CU_ASSERT_EQUAL(report_data(&buffer_5),EMPTY);
	}

	for(i=0; i<(COUNT/2) ; i++)
	{
		
			CU_ASSERT_EQUAL(pop_data(&buffer_5, &data_pop),EMPTY);
	}
	

	CU_ASSERT_EQUAL(delete_CB(&buffer_5),SUCCESS);
}

void test_resize_CB() //suite5
{
	int i;
     for(p= parameter_value,i=0; i<(COUNT/2) ; i++, p++)
	{
		CU_ASSERT_EQUAL(insert_data(&buffer_6,*p),-4);
	}

	CU_ASSERT_EQUAL(resize_CB(&buffer_6,COUNT/2),SUCCESS);

	 for(p= parameter_value,i=0; i<(COUNT/2) ; i++, p++)
	{
		CU_ASSERT_EQUAL(insert_data(&buffer_6,*p),SUCCESS);
	}

	CU_ASSERT_EQUAL(resize_CB(&buffer_7,-2),ERROR);
	CU_ASSERT_EQUAL(resize_CB(&buffer_7,0),ERROR);

	CU_ASSERT_EQUAL(delete_CB(&buffer_6),SUCCESS);
	CU_ASSERT_EQUAL(delete_CB(&buffer_7),SUCCESS);



}

void test_clear_buffer() //suite5
{

   CU_ASSERT_EQUAL(clear_buffer(&buffer_8),SUCCESS);
   CU_ASSERT_EQUAL(clear_buffer(&buffer_8),EMPTY);

}

/*main function*/
int main(void)
{

	 if (CUE_SUCCESS != CU_initialize_registry())
	return CU_get_error();

	CU_pSuite pSuite1 = NULL;
    /* initialize the CUnit test registry */
   

 	/* add a suite to the registry */
 	pSuite1 = CU_add_suite("Suite_1", init_suite_init_CB, clean_suite);
    if (NULL == pSuite1)
    {
	 	CU_cleanup_registry();
	    return CU_get_error();
	}

    /* add the tests to the suite */
    /* NOTE - ORDER IS IMPORTANT - MUST TEST fread() AFTER fprintf() */
    if ((NULL == CU_add_test(pSuite1, "test of fprintf()", test_init_CB)))
    {
	    CU_cleanup_registry();
      	return CU_get_error();
	}
/***************************************************************************/

	CU_pSuite pSuite2 = NULL;
    
 	/* add a suite to the registry */
 	pSuite2 = CU_add_suite("Suite_2", init, clean_suite);
    if (NULL == pSuite2)
    {
	 	CU_cleanup_registry();
	    return CU_get_error();
	}


	if ((NULL == CU_add_test(pSuite2, "test of fprintf()", test_insert_data)))
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

/***************************************************************************/

	CU_pSuite pSuite3 = NULL;
    

 	/* add a suite to the registry */
 	pSuite3 = CU_add_suite("Suite_3", init_delete, clean_suite);
    if (NULL == pSuite3)
    {
		CU_cleanup_registry();
	    return CU_get_error();
	}

	if ((NULL == CU_add_test(pSuite3, "test of fprintf()", test_delete_data)))
	{
	    CU_cleanup_registry();
	    return CU_get_error();
	}
/***************************************************************************/

	CU_pSuite pSuite4 = NULL;
    

 	/* add a suite to the registry */
 	pSuite4 = CU_add_suite("Suite_4", init_suite_report_data, clean_suite);
    if (NULL == pSuite4)
    {
		CU_cleanup_registry();
	    return CU_get_error();
	}
	if ((NULL == CU_add_test(pSuite4, "test of fprintf()", test_pop_and_report_data)))
	{
	        CU_cleanup_registry();
	        return CU_get_error();
	}
/***************************************************************************/

	CU_pSuite pSuite5 = NULL;
    

 	/* add a suite to the registry */
 	pSuite5 = CU_add_suite("Suite_5", init_suite_resize, clean_suite);
    if (NULL == pSuite5)
    {
		CU_cleanup_registry();
	    return CU_get_error();
	}

	if ((NULL == CU_add_test(pSuite5, "test of fprintf()", test_resize_CB)))
	{
	        CU_cleanup_registry();
	        return CU_get_error();
	}

/***************************************************************************/

	CU_pSuite pSuite6 = NULL;
    

 	/* add a suite to the registry */
 	pSuite6 = CU_add_suite("Suite_6", init_suite_clear, clean_suite);
    if (NULL == pSuite6)
    {
		CU_cleanup_registry();
	    return CU_get_error();
	}
	if ((NULL == CU_add_test(pSuite6, "test of fprintf()", test_clear_buffer)))
	{
	        CU_cleanup_registry();
	        return CU_get_error();
	}

/***************************************************************************/
    /* Run all tests using the CUnit Basic interface */
    random_generator(2);
	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	CU_cleanup_registry();
	return CU_get_error();
}
