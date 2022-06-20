




void main(void)
{
	
	u32 arr1[1000] = {0};
	u32 arr2[1000] ;
	u32 arr3[1000] = {0};
	u32 arr4[1000] ;
	
	MRCC_voidSystemClockInit();
	MRCC_voidEnablePeripheralClock(RCC_AHB , 0);
	
	MDMA_voidChannelInit();
	
	MNVIC_voidInterruptEnable(11);
	
	MDMA_voidChannelStart(arr1 , arr2 , 1000 );
	
	for(u16 i=0 ; i<1000 ; i++)
	{
		arr4[i] = arr3[i];
	}
	
	
	while(1)
	{
		
	}
}

void DMA1_Channel_IRQHnadler(void)
{
	/* clear GIF flags */
	DMA->IFCR = 1<<0;
	/* clear TC flags */
	DMA->IFCR = 1<<1;
}