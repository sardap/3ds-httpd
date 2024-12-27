<script setup lang="ts">
import HostingInfo from './components/HostingInfo.vue'
import BookRanking from './components/BookRanking.vue'
</script>

<template>
  <header>
    <div class="wrapper">
      <h1>PAUL SARDA BOOK CLUB</h1>
    </div>
  </header>
  <main>
    <div class="section">
      <h2>BOOK REVIEWS</h2>
      <BookRanking />
    </div>
    <hr />
    <div class="section">
      <h2>ALSO THIS WEBSITE IS HOSTED ON A 2DS?</h2>
      <HostingInfo />
    </div>
  </main>
</template>

<style scoped>
header {
  line-height: 1.5;
}

.section {
  padding-bottom: 2em;
}
</style>
